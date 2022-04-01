# /usr/bin/python

from dataclasses import replace


def XOR(str1, str2):  # 实现模2减法
    ans = ''
    if str1[0] == '0':
        return '0', str1[1:]
    else:
        for i in range(len(str1)):
            if (str1[i] == '0' and str2[i] == '0'):
                ans = ans + '0'
            elif (str1[i] == '1' and str2[i] == '1'):
                ans = ans + '0'
            else:
                ans = ans + '1'
    return '1', ans[1:]

def CRC_Encoding(str1,str2):  # CRC编码
    lenght = len(str2)
    str3 = str1 + '0' * (lenght - 1)
    ans = ''
    yus = str3[0:lenght]
    for i in range(len(str1)):
        str4, yus = XOR(yus, str2)
        ans = ans + str4
        if i == len(str1) - 1:
            break
        else:
            yus = yus + str3[i + lenght]
    return str1 + yus

def Character_Padding(str0,str1,str2): # 正变换
    flag1 = str0.find(str1)
    location1 = flag1
    while flag1 != -1:
        str0 = str0[:location1] + str0[location1:].replace(str1,str2,1)
        flag1 = str0[location1 + 4:].find(str1)
        location1 = len(str0[:location1]) + str0[location1 + 4:].find(str1) + 4
    return str0

#读取数据
context = input('请输入要编码的比特流:')

# 正变换
context = Character_Padding(context,'1000','10000')
context = Character_Padding(context,'0111','01111')

# CRC编码
Generator_Polynomial = '100000111'
Check_bits = CRC_Encoding(context,Generator_Polynomial)

# 添加头部尾部
flag = input("字符帧or汉字帧:")
if flag == '0':
    head = '100010'
else:
    head = '100011'
tail = '01110'

Frame = head + Check_bits + tail
# 写入文件
with open('encode_output.txt','w') as f:
    f.write(Frame)
