#coding=utf-8
#
d = {}
d['a'] = (1,35)
d['b'] = (2,37)
d['c'] = (3,39)

for k in d:
	print k

#from collections import OrderedDict

d = OrderedDict()
d['a'] = (1,35)
d['b'] = (2,37)
d['c'] = (3,39)
for k in d:
	print k


from time import time
from random import randint
from collections import OrderedDict

d = OrderedDict()
players = list('ABCDEFGH')
start = time()

for i in xrange(8):
	raw_input()
	p = players.pop(randint(0, 7 - i))
	end = time()
	print i + 1, p, end - start
	d[p] = (i+1, end - start)

print
print '-' * 20

for k in d:
	print k, d[k]





