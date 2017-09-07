#coding=utf-8


#使用类似于枚举类型的定义
NAME,AGE,SEX,EMAIL = xrange(4)

student = ('Jim', 15, 'man', '563594467@qq.com')
print student
print student[NAME]
print student[AGE]
print student[SEX]
print student[EMAIL]
print
print
#使用collections.namedtuple方式

from collections import namedtuple

student = namedtuple('student', ['name', 'age', 'sex', 'email'])
print student

s1 = student('yuyang', 24, 'man', '563594467@qq.com')
print s1
print s1.name
print s1.email

#判断是否为元组
print isinstance(s1,tuple)