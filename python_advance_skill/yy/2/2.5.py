#coding=utf-8
from random import randint, sample

#从abcxyz中随机选取3到6个元素
d = sample('abcxyz', randint(3,6))
print d

s1 = {x: randint(1,4) for x in sample('abcxyz', randint(3,6)) }
print s1

s2 = {x: randint(1,4) for x in sample('abcxyz', randint(3,6)) }
print s2

s3 = {x: randint(1,4) for x in sample('abcxyz', randint(3,6)) }
print s3

#直接用for循环对字典的键进行迭代
res = []
for y in s1:
	if y in s2 and y in s3:
		res.append(y)
print res


print s1.viewkeys()
print s1.viewvalues()
print s1.viewkeys() & s2.viewkeys() & s3.viewkeys()


print map(dict.viewkeys, [s1,s2, s3])

print reduce(lambda a, b: a&b, map(dict.viewkeys, [s1,s2, s3]))