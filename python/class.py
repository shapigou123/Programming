#coding=utf-8
'''
p1 = Person()
p1.name = 'Bart'

p2 = Person()
p2.name = 'Adam'

p3 = Person()
p3.name = 'Lisa'

L1 = [p1, p2, p3]
L2 = sorted(L1, lambda p1,p2:cmp(p1.name,p2.name))


print L2[0].name
print L2[1].name
print L2[2].name

print cmp('a','b')
'''

'''
class Person(object):
    def __init__(self, name, gender, birth, **kw):
        self.name = name
        self.gender = gender
        self.birth = birth
        for k, v in kw.iteritems():
            setattr(self, k, v)

xiaoming = Person('Xiao Ming', 'Male', '1990-1-1', job='Student', weight='120')

print xiaoming.name
print xiaoming.gender
print xiaoming.job
print xiaoming.weight
'''

class Person(object):
    count = 0
    def __init__(self, name):
        Person.count = Person.count + 1
        self.name = name
p1 = Person('Bob')
#直接访问类属性
print Person.count
print p1.count
# => 1
p2 = Person('Alice')
print Person.count
# => 2
p3 = Person('Tim')
print Person.count

Person.count = 100
print Person.count
