#coding=utf-8

def function(val):
	if val >= passline:
		print ('%d pass' %val)
	else:
		print('failed')
	def in_func():#会把val添加到该函数的属性中
		print val
	in_func()
	return in_func

f = function(89)	
f() #in_func
print f.__closure__


'''
def func_100(val):
	passline = 60
	if val >= passline:
		print ('%d pass' %val)
	else:
		print ('failed')

def func_150(val):
	passline = 90
	if val >= passline:
		print ('%d pass' %val)
	else:
		print ('failed')

def set_passline(passline):
	def cmp(val):#cmp就是一个闭包
		if val >= passline:
			print ('pass')
		else:
			print('failed')
	return cmp

#f_100 = set_passline(60) #passline = 60
#f_150 = set_passline(90) #passline = 90
#print(type(f_100))
#print(f_100.__closure__)
#f_100(89)
#f_100(59)
#f_150(89)
'''