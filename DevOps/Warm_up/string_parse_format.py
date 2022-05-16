# /usr/bin/python
# 命令行指定输入、输出文件名称 例如： python string_parse_format.py input.txt output.txt 

import sys

filenames = sys.argv
input_filename = filenames[1]
output_filename = filenames[2]

with open(input_filename,'r') as f:
    context = f.readlines()

for i in range(0,len(context)):
    strdata = context[i]
    number = filter(str.isdigit,  strdata)
    number = list(number)
   
    if i != len(context) - 1:
        with open(output_filename,'a+') as f:
            f.write(f'{number[0]}{number[1]}{number[2]}-{number[3]}{number[4]}{number[5]}-{number[6]}{number[7]}{number[8]}''\n''')
    else:
        with open(output_filename,'a+') as f:
            f.write(f'{number[0]}{number[1]}{number[2]}-{number[3]}{number[4]}{number[5]}-{number[6]}{number[7]}{number[8]}')
