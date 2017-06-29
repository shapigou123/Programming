#coding=utf-8
#
#


def dec(func):
	print 'call dec'
	def in_dec(*arg):
		print 'in_dec arg = ', arg
		if len(arg) == 0:
			return 0
		for val in arg:
			if not isinstance(val, int):
				return 0
		return func(*arg) #返回的是值
	return in_dec #返回的是函数

#这里会调用我们的dec代码并将my_sum1作为参数传给dec，
#dec返回in_dec，in_dec就被my_sum1接收了
#将my_sum1重新赋值
#
#@dec 的效果就类似于my_sum1 = dec(my_sum1)
@dec
def my_sum1(*arg):#my_sum1 = in_dec
	print 'my_sum1 arg = ', arg
	return sum(arg)
my_sum1(1,2,3,4,5) 
#调用my_sum1
#第一步：装饰器会返回一个新的函数，也就是in_dec，并被my_sum1接收
#再次调用my_sum1的时候，实际上是调用的in_dec

def my_average1(*arg):
	return sum(arg)/len(arg)

