#coding=utf-8
from random import randint, sample
from collections import Counter
from collections import deque
from collections import OrderedDict
import re
from time import time

###############################################
'''
from random import randint
data = [randint(-10,10) for x in xrange(10)]
s = set(data)
print s
'''
###############################################



############为元祖中的每个元素命名##############

############1.定义一系列数值常量################
'''
NAME,AGE,SEX,EMAIL = xrange(4)
student = ('Jim', 15, 'man', '563594467@qq.com')
print student
print student[NAME]
print student[AGE]
print student[SEX]
print student[EMAIL]
'''
################################################




#######2.collections.namedtuple代替内置元组#####
'''
from collections import namedtuple
 
student = namedtuple('student', ['name', 'age', 'sex', 'email'])
print student

s1 = student('yuyang', 24, 'man', '563594467@qq.com')
print s1
print s1.name
print s1.email

print isinstance(s1,tuple)
'''
################################################




############如何统计序列中元素出现频度##########

############1.利用列表解析进行次数统计##########
'''
data = [randint(0,5) for x in xrange(10)]

count = dict.fromkeys(data, 0)

for x in data:
	count[x] += 1
print count

count = sorted(count.items(), key=lambda x:x[1], reverse=True)

for x in xrange(3):
	print count[x]
'''
################################################


############2.使用collections.counter对象#######
'''
c = Counter(data)
print c
print c.most_common(3)
'''
################################################


#########3.对某英文文章的单词进行统计，######
######找到出现次数最高的10个词和的次数#######
'''
txt = open('bible.txt').read()
c2 = Counter(re.split(r'\W+', txt))
print c2.most_common(5)
'''
################################################



#########根据字典中值得大小，对字典的项排序#####
#
########1.使用内置函数sorted（效率相对较快）####
'''
data = [randint(-10,10) for x in xrange(10)]
print data
print sorted(data)
print sorted(data, reverse=True)

d = {x:randint(60,100) for x in 'xyzabc'}
print d
#默认对key进行排序
print sorted(d)
print sorted(d.values())

print iter(d)
print list(iter(d))
'''
##############################################



######2.list元素个数很多时可能会浪费内存空间########
'''
d = {x:randint(60,100) for x in 'xyzabc'}
l = zip(d.keys(), d.values())
l1 = zip(d.iterkeys(), d.itervalues())
print l
#print l1
print dict(l)

print "sorted:", sorted(dict(l).values())
 
print ('a', 99) > ('A',99)
print ('a', 98) > ('a',99)

d1 = dict(zip(d.iterkeys(), d.itervalues()))
d2 = sorted(d1.iteritems(), key=lambda x:x[0])
print d2

#print d1.items()
#print d1.iteritems()
'''



##############找到多个字典中的公共键###########

'''
d = sample('abcxyz', randint(3,6))
#结果为list
#print d

s1 = {x:randint(1,4) for x in sample('abcxyz', randint(3,6))}
#print s1

s2 = {x:randint(1,4) for x in sample('abcxyz', randint(3,6))}
#print s2

s3 = {x:randint(1,4) for x in sample('abcxyz', randint(3,6))}
#print s3
#

#res = []
#for x in s1.values():
#	if x in s2.values() and x in s3.values():
#		res.append(x)
#print res

res = []
for x in s1:
	if x in s2 and x in s3:
		res.append(x)
print res

	#类型为dict_keys([])
#print s1.viewkeys()
	#false
#print isinstance(s1.viewkeys(), set)
#print type(s1.viewkeys())
	#类型为dict_values([])
#print s1.viewvalues()

print s1.viewkeys() & s2.viewkeys() & s3.viewkeys()

#print map(dict.viewkeys, [s1, s2, s3])
#print map(dict.viewvalues, [s1, s2, s3])
print reduce(lambda a, b:a&b, map(dict.viewkeys, [s1, s2, s3]))
'''
####################################################




##############让字典保持有序##################
 
###1.使用collections.OrderdDict构建有序字典###
'''
d = {}
d['a'] = (1,35)
d['b'] = (2,37)
d['c'] = (3,39)

for k in d:
	print k

d1 = OrderedDict()
d1['a'] = (1,35)
d1['b'] = (2,37)
d1['c'] = (3,39)

for k in d1:
	print k
'''

'''
d = OrderedDict()
players = list('ABCDEFGH')

#print players.pop(randint(0,7))
#print players
start = time()


for i in xrange(8):
	raw_input()
#随机从players中弹出随机索引为[0...7-i]的元素
#p为弹出的元素
	p = players.pop(randint(0,7-i))
	end = time()
	print i+1, p, end-start
	d[p] = (i+1, end-start)

print
print '-' *20

for k in d:
	print k, d[k]
'''
#######################################




##########实现用户的历史记录功能########
#
#######1.用队列来实现历史记录功能#######

'''
#队列的初始值为空，元素个数个5 
q = deque([], 5)
print q

q.append(1)
q.append(2)
q.append(3)
q.append(4)
q.append(5)
print q
q.append(6)
print q
'''

'''
N = randint(0,100)
his = deque([], 5)
def guess(k):
	if k == N:
		print 'right'
		return True
	elif k < N:
		print '%s is less than N' % k
		return False
	else:
		print '%s is greater than N' % k
		return False

while True:
	line = raw_input("please input a number: ")
	if line.isdigit():
		k = int(line)
		his.append(k)
		if guess(k):
			break
	elif line == 'history' or line == 'h?':
		print list(his)
	elif line == 'quit' or line == 'exit':
		break
	else:
		print "input error"
		continue
'''

'''
q = ['hello', '12345']
import pickle
pickle.dump(q, open('test.txt', 'w'))

q2 = pickle.load(open('test.txt'))
print q2
'''

'''
import json
print json.dumps({'a': 'Runoob', 'b': 7}, sort_keys=True, 
	indent=4, separators=(',', ': '))
'''

l = [1, 2, 3, 4]
s = 'abcde'

#for x in l: print x
#for x in s: print x
#print iter(l)
#print iter(s)
#print iter(5)

t =iter(l)
print t.next()
print t.next()
print t.next()
print t.next()
#print t.next()
