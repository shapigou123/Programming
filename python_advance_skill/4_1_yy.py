#coding=utf-8
import json
import re
import os, stat
'''
l = [1, 2, 3]

t = tuple(l)
print t

s = set(l)
print s
'''

'''
s = u'你好'
print s.encode('utf8')

print s.encode('gbk')
'''

def mySplit(s, ds):
	res = [s]
	for d in ds:
		t = []
		map(lambda x: t.extend(x.split(d)), res)
		res = t
	return [x for x in res if x]

s = 'ab;cd|efg|hi,jkl|mn\topq;;rst,uvw\txyz'
print mySplit(s, ';,|\t')

print re.split(r'[,;|\t]+', s)

p1 = ["<0112>", "<32>", "<1024x768>", "<60>", "<1>", "<100.0>", "<500.0>"]
s = ' '
for p in p1:
	s += p
	print s