# /usr/bin/python
#海明码编码

import math

while True:
    number = input("请输入需要编码的数:")
    Check_code_length = 2

    #计算海明码长度
    while len(number) + Check_code_length + 1 > 2 ** (Check_code_length):
        Check_code_length = Check_code_length + 1
    Hamming_code_length = Check_code_length + len(number)

    #初始化海明码为全0列表
    Hamming_code = [0 for i in range(Hamming_code_length)]

    #计算校验位和信息位
    Check_bits = []
    Information_bits = []
    for i in range(0,Hamming_code_length):
        if math.log2(i + 1) % 1 == 0:
            Check_bits.append(i)
        else :
            Information_bits.append(i)

    #将数据位信息添加到海明码列表中,并计算数据位与校验位关系
    i = 0
    Information_bit_bins = [] 
    for Information_bit in Information_bits:
        Hamming_code[Information_bit] = int(number[i])
        i = i + 1
        Information_bit_bins.append(bin(Information_bit + 1).replace('0b',''))
    
    for i in range(0,Check_code_length):
        flag =0
        for j in range(0,len(Information_bit_bins)):
            Information_bit_bin= Information_bit_bins[j]  
            if len(Information_bit_bin)-1-i >= 0 and int(Information_bit_bin[len(Information_bit_bin)-1-i]) == 1 and int(number[j]) == 1:
                flag = flag + 1
        Hamming_code[Check_bits[i]] = flag % 2
    H = [str(i) for i in Hamming_code]
    print(''.join(H))
