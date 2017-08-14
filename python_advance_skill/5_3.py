#coding=utf-8
from telnetlib import Telnet
from sys import stdin, stdout
from collections import deque

class TelnetClient(object):
    def __init__(self, addr, port=23):
        #需要连接服务器的ip地址
        self.addr = addr
        #端口
        self.port = port
        self.tn = None

    def start(self):
        raise Exception('Test')

        # user
        t = self.tn.read_until('login: ')
        stdout.write(t)
        user = stdin.readline()
        self.tn.write(user)

        # password
        t = self.tn.read_until('Password: ')
        if t.startswith(user[:-1]): t = t[len(user) + 1:]
        stdout.write(t)
        self.tn.write(stdin.readline())

        #登录之后就进入到了服务器的shell中了
        t = self.tn.read_until('$ ')
        stdout.write(t)
        while True:
            #在这个循环中，使用一些shell命令与服务器进行交互
            uinput = stdin.readline()
            if not uinput:
                break
            self.history.append(uinput)
            self.tn.write(uinput)
            t = self.tn.read_until('$ ')
            stdout.write(t[len(uinput) + 1:])

    def cleanup(self):
        pass

    def __enter__(self):
        #tn是telnet的连接对象
        self.tn = Telnet(self.addr, self.port)
        #存储用户的操作记录
        self.history = deque()
        return self 

    def __exit__(self, exc_type, exc_val, exc_tb):
        #在with语句块中可能会产生异常
        #exc_type异常的类型
        #exc_val异常的值
        #exc_tb异常的trees栈信息
        #在不发生异常时，它们的值都是None
        print 'In __exit__'

        #关闭连接服务器的socket
        self.tn.close()
        self.tn = None
        with open(self.addr + '_history.txt', 'w') as f:
            #把用户的操作记录写到到文件中去
            f.writelines(self.history)
        return True

#在调用这个with语句的时候，是在这个TelnetClient('127.0.0.1')
#对象上进行with操作。
#1.首先调用__init__得到对象，
#2.然后对该对象进行with操作时会进入到__enter__方法
with TelnetClient('127.0.0.1') as client:
    client.start()

print 'END'

'''
client = TelnetClient('127.0.0.1') 
print '\nstart...'
client.start()
print '\ncleanup'
client.cleanup()
'''
