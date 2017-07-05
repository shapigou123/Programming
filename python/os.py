#coding=utf-8
from os.path import isdir,isfile #第一种导入方式
import os
import os.path
from os import path

class Person(object):
    pass
xiaoming = Person()
xiaohong = Person()
print xiaoming
print xiaohong
print xiaoming == xiaohong

print isdir(r'C:\Windows')
print isfile(r'C:\Windows\notepad.exe')