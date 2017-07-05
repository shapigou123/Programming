#coding=utf-8
import time

def performance(unit):
    def performance_decorator(f):
        def fn(*args, **kw):
            t1 = time.time()
            f(*args, **kw)
            t2 = time.time()
            print 'call %s() in %f%s' % (f.__name__,(t2-t1), unit)
            return f(*args, **kw)
        return fn
    return performance_decorator

@performance('ms')
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))

print factorial(10)

