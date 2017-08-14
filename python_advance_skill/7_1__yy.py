#coding=utf-8


#继承内置的tuple
class IntTuple(tuple):
	#修改实例化行为，就要修改__new__方法，是一个静态方法
	#当我们创建一个实例的时候，__new__要先于__init__方法
	#第一个参数是一个类对象，其他参数和__init__一样
	def __new__(cls, iterable):
		#使用一个生成器对象，下面就是生成器表达式
		g = (x for x in iterable if isinstance(x,int) 
			and x>0)
		#在其内部调用父类的__new__方法，来创建真正的tuple
		#cls是当前类的一个子类
		return super(IntTuple,cls).__new__(cls,g)

	#考虑改变传入的iterable参数手工指定[1,4]，但任然不行！
	#在self在传入到__init__后，内置的元组就已经创建好了。所以
	#在之后的任何位置都不能改变。考虑是谁创建了self这个实例__new__
	def __init__(self, iterable):
		#super(IntTuple,self).__init__([1, 6, 3])
		#print self
		
		#调用父类的__init__方法
		super(IntTuple,self).__init__(iterable)

		#after
		#在这里不能修改self了，self是内置类型tuple的实例
		#而tuple是不可变对象，即不能从self中删除元素
		
t = IntTuple([1, -1, 'abc', 6, ['x', 2], 3])
print t


class Player(object):
	def __init__(self, uid, name, stat=0, level=1):
		self.uid = uid
		self.name = name
		self.stat = stat
		self.level = level

#Player2的实例要比Player的实例使用的内存要小！
class Player2(object):
	__slots__ = ['uid', 'name', 'stat', 'level']
	def __init__(self, uid, name, stat=0, level=1):
		self.uid = uid
		self.name = name
		self.stat = stat
		self.level = level

with open('demo.txt', 'w') as f:
	f.write('abcdef')
	f.writelines(['xyz\n', '123\n'])
#f.close()