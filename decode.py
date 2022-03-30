# /usr/bin/python

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

def CRC_Decoding(str1, str2):  # CRC解码
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
    return yus == '0' * len(yus)

def Inverse_Character_Padding(str0,str1,str2): # 逆变换
    flag1 = str0.find(str1)
    location1 = flag1
    while flag1 != -1:
        str0 = str0[:location1] + str0[location1:].replace(str1,str2,1)
        flag1 = str0[location1 + 3:].find(str1)
        location1 = len(str0[:location1]) + str0[location1 + 3:].find(str1) + 3
    return str0

# 读取数据并去掉头部尾部
Frame = input('请输入要解码的比特流:')
first = Frame.find('10001')
last1 = Frame[::-1].find('01110')
last = len(Frame) - last1 - 5
if first == -1 or last1 == -1 or first > last:
    print('首尾定位失败,请重传帧')
    exit()
context = Frame[first + 6:last]

# CRC验证
Generator_Polynomial = '100000111'
flag = CRC_Decoding(context,Generator_Polynomial)
if flag :   # CRC验证正确
    print('CRC检验正确')
    context = context[:len(context)-8]
    # 逆变换
    context = Inverse_Character_Padding(context,'01111','0111')
    context = Inverse_Character_Padding(context,'10000','1000')
    # 清空输出文件
    with open('decode_output.txt','w') as f:
        f.truncate()
    with open('decode_output.txt','a+') as f:
        if Frame[first + 5] == '0':
            for i in range(0,int(len(context) / 8)):
                f.write(context[8 * i:8 * (i + 1)])
        if Frame[first + 5] == '1':
            for i in range(0,int(len(context) / 16)):
                f.write(context[16 * i:16 * (i + 1)])
else :
    print('CRC检验失败,请重传帧')
    exit()
