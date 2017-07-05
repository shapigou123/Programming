#include <iostream>
#include <string>
#include "MyQueue.h"
#include "Customer.h"

using namespace std;
int main(void)
{
#if 0
	MyQueue *p = new MyQueue(4);	//定义一个环形队列的对象指针
	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(14);
	p->EnQueue(16);
	//p->DeQueue();
	cout<<"遍历"<<endl;
	p->QueueTraverse();
	
	int e = 0;
	p->DeQueue(e);
	cout<<endl;
	cout<<"出队："<<e<<endl;
	
	p->DeQueue(e);
	cout<<"出队："<<e<<endl;
	cout<<endl;
	
	p->QueueTraverse();	//连续出两次队列后再无法遍历打印出队列
	cout<<endl;
	
	p->ClearQueue();
	
	p->QueueTraverse();
	
	p->EnQueue(20);
	p->EnQueue(30);
	cout<<"遍历"<<endl;
	p->QueueTraverse();
#endif
	MyQueue *p = new MyQueue(4);

	//此时我们插入的元素不是一个普通的int 类型，而是一个个Customer对象
	//通过Customer来实例化对象
	Customer c1("lisi", 18);
	Customer c2("zhangsan", 20);	
	Customer c3("zhangsan", 22);
	Customer c4("zhangsan", 24);
	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);
	p->EnQueue(c4);
	
	p->QueueTraverse();
	
	Customer c5("",0);
	p->DeQueue(c5);
	cout<<"移除的元素：";
	c5.printInfo();
	cout<<"移除后："<<endl;
	p->QueueTraverse();
	
	delete p;
	p = NULL;
	
	//system("pause");
	return 0;
}