#coding=utf-8
#
def deco(func):
	def in_deco(x,y):
		print 'in in_deco'
		func(x,y)
	print 'call deco'
	return in_deco

#bar为被装饰的函数
#1：调用deco，bar作为参数传给了deco
#2：deco返回一个函数对象in_deco 
#3: 即deco(bar)->in_deco
#4：bar被赋予新的值，bar = in_deco
#5: 最后调用bar的时候，其实就是调用的in_deco，
#	而在in_deco内部又调用了原始的bar函数
@deco
def bar(x,y):
	print 'in bar', x+y
bar(1,2)