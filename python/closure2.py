#coding=utf-8

def my_sum(*arg):
	if len(arg) == 0:
		return 0
	for val in arg:
		if not isinstance(val, int):
			return 0
	return sum(arg)

def my_average(*arg):
	if len(arg) == 0:
		return 0
	for val in arg:
		if not isinstance(val, int):
			return 0
	return sum(arg)/len(arg)

def my_sum1(*arg):
	print 'my_sum1 arg = ', arg
	return sum(arg)

def my_average1(*arg):
	return sum(arg)/len(arg)

def dec(func):
	def in_dec(*arg):
		print 'in_dec arg = ', arg
		if len(arg) == 0:
			return 0
		for val in arg:
			if not isinstance(val, int):
				return 0
		return func(*arg) #返回的是值
	return in_dec #返回的是函数

my_sum1 = dec(my_sum1)
#第一步：调用dec函数，把my_sum1传进函数
#第二步：此时in_dec就是一个闭包，此时my_sum1就会放到in_dec的属性中
		 #就可以在in_dec中直接对my_sum1进行使用
#第三步：真正调用时，先调用的是的in_dec，然后再调用func
#对参数的树立都是交给in_dec
#最后的计算才交给func
#
#
print my_sum1(1,2,3,4)
#print my_average(1,2,3,4,'hello')
#print my_sum(1,2,3,4,'hello')
#print my_average1(1,2,3,4,5)
#print my_sum1(1,2,3,4,5)


