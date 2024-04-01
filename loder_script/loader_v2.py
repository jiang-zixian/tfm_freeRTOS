#!/usr/bin/python3
from elftools.elf.elffile import ELFFile

elf_path = "../build/bin/ns_app.elf"
output_relocation_info_path = (
    "/home/jiangzixian/tfm_freeRTOS_dwt/platform/ext/target/stm/aslr_freertos_nsapp/loader/src/relocation.c"
)
output_functions_info_path = (
    "/home/jiangzixian/tfm_freeRTOS_dwt/platform/ext/target/stm/aslr_freertos_nsapp/loader/src/func.c"
)
need_relocation_secions = ["text"]

code_start = 0x08005000


def section_index(section, sections):
    for i in range(len(sections)):
        if section == sections[i][1]:
            return i
    return -1


def output_relocation_info(info):
    with open(output_relocation_info_path, "w") as f:
        f.write('#include "relocation.h"\n')
        f.write("\n")
        f.write("uint32_t table_size = ")
        f.write(str(len(info)) + ";\n")
        f.write("\n")
        f.write("relocation_info_t relocation_info[")
        f.write(str(len(info)))
        f.write("] = {\n")
        for entry in info:
            address = hex(entry[0])
            value = hex(entry[1])
            type = entry[2]
            name = entry[3]
            f.write(
                "    {"
                + address
                + ", "
                + value
                + ", "
                + str(type)
                + "},"
                + "  //"
                + name
                + "\n"
            )
        f.write("};\n")


def output_functions_info(functions_info):
    with open(output_functions_info_path, "w") as f:
        f.write('#include "func.h"\n')
        f.write("\n")
        f.write("uint32_t func_info_size = ")
        f.write(str(len(functions_info)) + ";\n")
        f.write("\n")
        f.write("func_info_t func_info[")
        f.write(str(len(functions_info)))
        f.write("] = {\n")
        for addr, size, name in functions_info:
            f.write(
                "    {"
                + hex(addr)
                + ", "
                + str(size)
                + ", "
                + str(0)
                + "},"
                + "  //"
                + name
                + "\n"
            )
        f.write("};\n")


def parse_symbol_table(elf_file):
    symbol_tables = elf_file.get_section_by_name(".symtab")
    table_infos = []
    # print("Symbol table '.symtab' contains %d entries:" % symbol_tables.num_symbols())
    # print("%8s %16s %5s %s" % ("Num", "Value", "Size", "Name"))
    for symbol in symbol_tables.iter_symbols():
        table_infos.append(
            [
                symbol["st_value"],
                symbol["st_size"],
                symbol["st_info"]["type"],
                symbol["st_shndx"],
                symbol.name if symbol.name else "",
            ]
        )
        # print(f'index {i}, value {symbol["st_value"]}, size {symbol["st_size"]}, type {symbol["st_info"]["type"]}, visibility {symbol["st_other"]["visibility"]}, bind {symbol["st_info"]["bind"]}, section index {symbol["st_shndx"]}, name {symbol.name if symbol.name else ""}')
    return table_infos


def parse_section_table(elf_file):

    # print("There are %d section headers, starting at offset 0x%x:" % (elf_file.num_sections(), elf_file['e_shoff']))
    sections_info = []
    for section in elf_file.iter_sections():
        sections_info.append([section["sh_addr"], section.name])
        # name = section.name
        # type_str = section['sh_type']
        # addr = section['sh_addr']
        # offset = section['sh_offset']
        # size = section['sh_size']
        # es = section['sh_entsize']
        # flags = section['sh_flags']
        # link = section['sh_link']
        # info = section['sh_info']
        # align = section['sh_addralign']
        # print(f'name {name}, type {type_str}, addr {hex(addr)}, offset {hex(offset)}, size {size}, es {es}, flags {flags}, link {link}, info {info}, align {align}')
    return sections_info


def generate_relocation_info(elf_file, symbol_tables, sections_info):
    rel_sections = []
    for index, section in enumerate(elf_file.iter_sections()):
        for need_section in need_relocation_secions:
            if section.name == ".rel." + need_section:
                rel_sections.append([section, index - 1])
    if rel_sections == []:
        print("Relocation table section not found.")
        return

    info = []

    # # Iterate over the relocation entries
    for rel_section, index in rel_sections:
        section_addr = sections_info[index][0]
        print(f"Relocation section {rel_section.name} at {hex(section_addr)}")
        for relocation in rel_section.iter_relocations():
            symbol = symbol_tables[relocation["r_info_sym"]]
            value = symbol[0] + sections_info[symbol[3]][0]
            offset = relocation["r_offset"] + section_addr
            relocation_type = relocation["r_info_type"]
            type = -1
            name = symbol[4]
            if relocation_type == 0x02:
                type = 0  # exception entry
            elif relocation_type == 0x03 and symbol[2] == "STT_FUNC":
                type = 1  # func pointer
            elif relocation_type == 0x03:
                type = 2  # data under function
            elif relocation_type == 0x60:
                type = 3  # data of some info, like "heap"
            elif relocation_type == 0x0A:
                type = 4  # func call
            elif relocation_type == 0x2F:
                type = 5  # absoultably address: movw
            elif relocation_type == 0x30:
                type = 6  # absoulately address: movt
            else:
                print(f"error occur: the symbol type not found: {name}")

            info.append([offset, value, type, name])
    return info


def generate_functions_info(symbol_tables, sections_info):
    functions_info = []
    for symbol in symbol_tables:
        if symbol[2] == "STT_FUNC":
            functions_info.append(
                [symbol[0] + sections_info[symbol[3]][0], symbol[1], symbol[4]]
            )
    return functions_info


def generate(elf_filename):
    with open(elf_filename, "rb") as f:
        elf_file = ELFFile(f)

        symbol_tables = parse_symbol_table(elf_file)
        sections_info = parse_section_table(elf_file)
        functions_info = generate_functions_info(symbol_tables, sections_info)
        output_functions_info(functions_info)
        info = generate_relocation_info(elf_file, symbol_tables, sections_info)
        output_relocation_info(info)


generate(elf_path)
