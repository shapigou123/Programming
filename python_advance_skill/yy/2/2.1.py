#coding=utf-8
################在列表中筛选数据#############
from random import randint
import timeit
import time
from time import clock
import datetime

data = [randint(-10,10) for x in xrange(10)]
#filter方式
start = clock()
#start = time.time()
#start = datetime.datetime.now()
tmp1 = filter(lambda x : x>=0, data)
finish = clock()
#finish = time.time()
#finish = datetime.datetime.now()
print "tmp1 =",tmp1
print (finish - start)

#列表解析方式
start = clock()
tmp2 = [x for x in data if x>=0]
finish = clock()

print "tmp2 =",tmp2
print (finish - start)

print time.ctime()

################在字典中筛选数据###################
d = {x:randint(20,100) for x in xrange(1,11)}
print d

#d = {k:v for k,v in d.iteritems() if v >90}
#print d

################在集合中中筛选数据###################
s = set(data)
print s
s = {x for x in s if x%3 == 0}
print s