#coding=utf-8

class myclass(object):
	"""docstring for myclass"""
	name = 'yuyang'
	def __init__(self, arg):
		#super(myclass, self).__init__()
		self.arg = arg
		
p1 = myclass('hello')
print p1.arg
print myclass.name
myclass.age = 12
print myclass.age
print p1.age

class Person(object):

    __count = 0

    def __init__(self, name):
        Person.__count =  Person.__count + 1
        self.name = name

p1 = Person('Bob')
p2 = Person('Alice')

class Person(object):

    def __init__(self, name, score):
        self.__name = name
        self.__score = score

    def get_grade(self):
        if self.__score < 60:
            return 'C'
        if self.__score < 60:
            return 'B'
        return 'A'

p1 = Person('Bob', 90)
p2 = Person('Alice', 65)
p3 = Person('Tim', 48)

print p1.get_grade()
print p2.get_grade()
print p3.get_grade()


class Person(object):

    def __init__(self, name, score):
        self.__name = name
        self.__score = score

    def get_grade(self):
        if self.__score >= 80:
            return 'A'
        if self.__score >= 60:
            return 'B'
        return 'C'

p1 = Person('Bob', 90)
p2 = Person('Alice', 65)
p3 = Person('Tim', 48)

print p1.get_grade()
print p2.get_grade()
print p3.get_grade()

class Person(object):

    def __init__(self, name, score):
        self.name = name
        self.score = score
        self.get_grade = lambda: 'A'

p1 = Person('Bob', 90)
print p1.get_grade #是一个绑定到实例的函数
print p1.get_grade() #方法调用

class Person(object):
    __count = 0
    def __init__(self, name):
        Person.__count = Person.__count + 1
        self.name = name
        print Person.__count

p1 = Person('Bob')
p2 = Person('Alice')

#print Person.__count
#
class Person(object):

    __count = 0

    @classmethod
    def how_many(cls):
        return cls.__count
        
    def __init__(self, name):
        self.name = name
        Person.__count =  Person.__count + 1

print Person.how_many()

p1 = Person('Bob')

print Person.how_many()

class Person(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

class Teacher(Person):

    def __init__(self, name, gender, course):
        super(Teacher, self).__init__(name, gender)
        self.course = course

t = Teacher('Alice', 'Female', 'English')
print t.name
print t.course

print type(t)
print dir(t)