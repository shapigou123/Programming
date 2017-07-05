#include <iostream>
#include "Coordinate.h"
#include "stack.h"

using namespace std;
#define BINARY		2
#define	OCTONARY	8
#define	HEXADECIMAL	16

int main(void)
{
	//我们使用的是类模板，要实例化变成模板类
	//MyStack<char> *pStack = new MyStack<char>(5);
	//MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);
	//MyStack *pStack = new MyStack(5);
	
	
	//若在栈中出现了10，则在数组中访问到的是A。但遍历的方法要改变
	char num[] = "0123456789ABCDEF";	
	
	MyStack<int> *pStack = new MyStack<int>(20);
	
	int N = 11;
	int mod = 0;	//存储余数
	while(N != 0 )
	{
		mod = N % HEXADECIMAL;
		pStack->push(mod);
		N = N/HEXADECIMAL; 	
	}
	
//	pStack->push(Coordinate(1,2));	//底
//	pStack->push(Coordinate(3,4));
//	pStack->push(Coordinate(5,6));
//	pStack->push('H');
//	pStack->push('K');
	
//	cout<<pStack->StackLength()<<endl;

//	pStack->StackTraverse(false);
	int elem = 0;
	while(!pStack->StackEmpty())
	{
		pStack->pop(elem);
		cout<<num[elem];
	}
	cout<<endl;
	
	//pStack->ClearStack();
	//cout<<pStack->StackLength()<<endl;
	
//	Coordinate elem;
//	pStack->pop(elem);
//	cout<<"pop的元素";
//	elem.printCoordinate();
	
//	pStack->pop(elem);
//	cout<<"pop的元素";
//	elem.printCoordinate();
	
	if(pStack->StackEmpty())
	{
		cout<<"栈为空"<<endl;
	}
	
	if(pStack->StackFull())
	{
		cout<<"栈为满"<<endl;
	}
	
//	pStack->StackTraverse(true);
	cout<<endl;
	
	
	delete pStack;
	pStack = NULL;
	
	return 0;
	
}