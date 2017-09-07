#coding=utf-8
from random import randint
from collections import deque

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
N = randint(0,100)
history = deque([], 5)
def guess(k):
	if k == N:
		print 'right'
		return True
	if k < N:
		print '%s is less than N' % k
	else:
		print '%s is greater than N' % k
	return False

while True:
	line = raw_input("please input a number: ")
	if line.isdigit():
		k = int(line)
		history.append(k)
		if guess(k):
			break
	elif line == 'history' or line == 'h?':
			print list(history)
'''

##############pickle##################

import pickle
print q
pickle.dump(q, open('history.txt', 'w'))
q2 = pickle.load(open('history.txt'))
print q2



