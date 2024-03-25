import re
import subprocess

relocation_path = 'platform/ext/target/stm/aslr_freertos_nsapp/loader/script/relocation.txt'
otutput_path = 'platform/ext/target/stm/aslr_freertos_nsapp/loader/src/relocation.c'
symbol_path = 'platform/ext/target/stm/aslr_freertos_nsapp/loader/script/symbol_table.txt'

text_start = 0x08055000
data_start = 0x20000100

symbol_dic = {}

def read_relocation_file(text_start = text_start):
    with open(relocation_path, 'r') as relocation_file:
        relocation_file.readline()
        line = relocation_file.readline()
        numbers = re.search(r'contains (\d+) entries', line)
        numbers = int(numbers.group(1))
        relocation_file.readline()
        with open(otutput_path, 'w') as output_file:
            output_file.write("#include \"relocation.h\"\n")
            output_file.write("uint32_t table_size = ")
            output_file.write(str(numbers) + ";\n")
            output_file.write("relocation_info_t relocation_info[")
            output_file.write(str(numbers))
            output_file.write("] = {\n")
            for i in range(0, numbers):
                line = relocation_file.readline().split()
                address = hex(int(line[0], 16) + text_start)
                value = hex(int(line[3], 16))
                if line[1][-2:] == '02':
                    value = hex(int(line[3], 16) + text_start)
                    output_file.write('    {' + address + ', ' + value + ', 0},\n')
                elif line[1][-2:] == '03':
                    if symbol_dic[(int(line[1], 16) >> 8)] == "FUNC":#func pointers
                        value = hex(int(line[3], 16) + text_start)
                        output_file.write('    {' + address + ', ' + value + ', 3},\n')
                    elif symbol_dic[(int(line[1], 16) >> 8)] == "OBJECT":#global
                        value =  hex(int(line[3], 16) + data_start)
                        output_file.write('    {' + address + ', ' + value + ', 1},\n')
                elif line[1][-2:] == '60':
                    value =  hex(int(line[3], 16) + data_start)
                    output_file.write('    {' + address + ', ' + value + ', 1},\n')
                else:
                    value = hex(int(line[3], 16)+ text_start)
                    output_file.write('    {' + address + ', ' + value + ', 2},\n')
            output_file.write("};\n")



command = "readelf -r /home/zys/repo/embedded/relo/build_re/bin/ns_app.elf > " + relocation_path
subprocess.run(command, capture_output=True, text=True, shell=True, check=True)

command = "readelf -s /home/zys/repo/embedded/relo/build_re/bin/ns_app.elf > " + symbol_path
subprocess.run(command, capture_output=True, text=True, shell=True, check=True)

with open(symbol_path, 'r') as symbol_file:
    symbol_file.readline()
    line = symbol_file.readline()
    numbers2 = re.findall(r'\d+', line)
    numbers2 = [int(num) for num in numbers2][0]
    symbol_file.readline()
    for i in range(0, numbers2):
        line = symbol_file.readline().split()
        symbol_dic[int(line[0][:-1])] = line[3]

read_relocation_file()

