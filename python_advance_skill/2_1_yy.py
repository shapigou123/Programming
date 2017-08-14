#coding=utf-8
from random import randint 
import timeit
import time


############################################
##############在列表中筛选数据##############
'''
data = [randint(-10,10) for x in xrange(10)]
print data


#1.迭代
res = []
for x in data:
	if x >= 0:
		res.append(x)
print res

#2.filter
print filter(lambda x : x >= 0, data)


t1 = timeit.Timer()
print  time.ctime()
print  time.time()


#3.列表解析
res1 = [x for x in data if x >= 0]
print res1
'''

############################################
##############在字典中筛选数据##############
'''
dict = {x: randint(60,100) for x in xrange(1,11)}
d = {k:v for k,v in dict.iteritems() if v > 90}
print dict
print d
'''

############################################
##############在集合中筛选数据##############
data = [randint(-10,10) for x in xrange(10)]

s = set(data)
print s
s = {x for x in s if x%3 == 0}
print s