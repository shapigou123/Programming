#coding=utf-8

from random import randint

data = [randint(0,10) for x in xrange(10)]
print "data:", data

#data作为字典的键，0作为初始值
count = dict.fromkeys(data, 0)
print "count1:", count

for x in data:
	count[x] += 1

print "count2:", count

count = sorted(count.items(), key = lambda x : x[1], reverse = True)
print count

for x in xrange(3):
	print count[x]

print 
print

#使用collections.counter对象对序列中的元素进行统计
from collections import Counter

c = Counter(data)
print c
print c.most_common(3)

#对某英文文章的单词进行统计，找到出现次数最高的10个词和他们的次数
import re

#打开并读取文件
txt = open('test.txt').read()

#利用正则表达式对非字母的字符串进行分割
#\W+ 匹配多个非数字字母的
c2 = Counter(re.split('\W+', txt))
print c2.most_common(10)