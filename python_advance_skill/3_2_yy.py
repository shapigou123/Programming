#coding=utf-8
from random import randint
from itertools import chain
'''
def f():
	print 'in f() 1'
	yield 1

	print 'in f() 2'
	yield 2

	print 'in f() 3'
	yield 3

g = f()
#print g

print g.next()
print g.next()
print g.next()

for x in g:
	print x
print g.__iter__() is g
'''

###################################
'''
class PrimeNumbers:
	def __init__(self, start, end):
		self.start = start
		self.end = end

	def isPrimeNum(self, k):
		if k < 2:
			return False

		for i in xrange(2, k):
			if k % i == 0:
				return False

		return True

	def __iter__(self):
		for k in xrange(self.start, self.end+1):
			if self.isPrimeNum(k):
				yield k

for x in PrimeNumbers(1,100):
	print x
'''
##########################################

'''
l = [1, 2, 3, 4]
print l.__iter__()
print iter(l)

print l.__reversed__()
print reversed(l)

l.reverse()
print l

print l[::-1]
'''

'''
l = [1, 2, 3, 4]

for x in reversed(l):
	print x

for x in iter(l):
	print x
''' 


######################################
'''
class FloatRange(object):
	"""docstring for FloatRange"""
	def __init__(self, start, end, step=0.5):
		self.start = start
		self.end = end
		self.step = step

	def __iter__(self):
		t = self.start
		while t <= self.end:
			yield t
			t += self.step

	def __reversed__(self):
		t = self.end
		while t >= self.start:
			yield t
			t -= self.step

for x in FloatRange(1,5,1):
	print x

for x in reversed(FloatRange(1, 5, 0.9)):
	print x
'''


#######################################
'''
from itertools import islice
f = open('bible.txt')

lines = f.readlines()

print islice(f,100, 200)

f.seek(0)
#迭代100行到102行
for line in islice(f, 100, 100):
	print line

#迭代100行到文件末
f.seek(0)
for line in islice(f, 100, 100):
	print line


#for x in lines:
#	print x
#for line in f:
#	print line

#for x in lines:
#	print x
#	

#########################################
l = range(10)
print l

t = iter(l)

for x in islice(t, 1, 5):
	print x


t1 = iter(l)
for x in t1:
	print x
'''

##########################################
'''
math = [randint(60,100) for x in range(20)]
chinese = [randint(60,100) for x in range(20)]
english = [randint(60,100) for x in range(20)]

#print math
#print chinese
#print english

res = []
for i in range(len(math)):
	res.append(chinese[i]+math[i]+english[i])
print res

res1 = []
l = zip(math, chinese, english)
for m, c, e in l:
	res1.append(c+m+e)
print res1
'''

e1 = [randint(60,100) for x in range(34)]
e2 = [randint(60,100) for x in range(38)]
e3 = [randint(60,100) for x in range(31)]
e4 = [randint(60,100) for x in range(30)]

count = 0
for s in chain(e1, e2, e3, e4):
	if s > 90:
		count += 1
print count