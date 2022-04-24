# /usr/bin/python
# 命令行传入需要计算的二进制数 例如：python binary_sum.py 1001 10000001  1010

import sys

sum = 0
Data_List = sys.argv

for i in range(1,len(Data_List)):
    Binary_String = Data_List[i] 
    k = 0

    for j in range(len(Binary_String)-1,-1,-1):
        sum = sum + int(Binary_String[j]) * 2 ** k
        k = k + 1

print(sum)