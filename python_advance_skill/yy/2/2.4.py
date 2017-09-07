#coding=utf-8

data1 = [9,2,4,0]
print sorted(data1)
print sorted(data1, reverse = True)

from random import randint
d1 = {x: randint(60,100) for x in 'xyzabc'}
print d1

#默认是对key进行排序
print sorted(d1)
print iter(d1)
print list(iter(d1))

#利用zip将两个列表合并生成一个列表，且列表的元素为元组
d2 = zip(d1.keys(), d1.values())
print d2
print "sorted:", sorted(d2)

#用d.itervalues()更加节省内存空间，因为它中间不会生成列表
d3 = zip(d1.itervalues(), d1.iterkeys())

#利用dict(zip(list1, list2)),将两个列表生产字典
d4 = dict(zip(d1.keys(), d1.values()))
print "d4:", d4
d5 = sorted(d4.items(), key = lambda x : x[1])
print "d5:", d5

#True
print ('a', 99) > ('A',99)
#False
print ('a', 98) > ('a',99)