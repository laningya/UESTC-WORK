# /usr/bin/python
# 命令行传入参数 例如: python word_freq.py word.txt

import sys
import json

def output(obj):
    print(json.dumps(obj))

filename = sys.argv
input_filename = filename[1]

with open(input_filename,'r') as f:
    context = f.read()

context = context.replace('.',' ')
context = context.replace('!',' ')
context = context.replace('?',' ')
context = context.lower()
word_list = context.split()

counts = {}

for word in word_list:
    counts[word] = counts.get(word,0) + 1
'''
items = list(counts.items())
items.sort(key=lambda x:x[1], reverse=True) 

for i in range(10):
    word, count = items[i]
    print ("{0:<10}{1:>5}".format(word, count))
'''
output(counts)