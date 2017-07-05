//#include"stdlib.h"
#include "stack.h"
#include "Coordinate.h"
#include <iostream>
using namespace std;

//将其粘贴到每一个成员函数的前面
template <typename T>
MyStack<T>::MyStack(int size )
{
	m_iSize = size;
	//m_pBuffer = new char[size];	
	//复杂数据类型作为栈的元素，MyStack中包含了Coordinate对象成员，
	//用这种写法时要有默认构造函数
	
	//m_pBuffer = new Coordinate[size];	
	
	m_pBuffer = new T[size];	
	m_iTop = 0;	//空栈，栈顶为0
}

template <typename T>
MyStack<T>::~MyStack()
{
	delete []m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::StackEmpty()
{
	if(0 == m_iTop)
		return true;
	else
		return false;
}
	
template <typename T>	
bool MyStack<T>::StackFull()
{
	if(m_iTop == m_iSize)	//初始时，m_iTop为0，来了一个元素后变为1；>= 也可以
	{
		return true;
	}
	return false;
}

template <typename T>
void MyStack<T>::ClearStack()
{
	m_iTop = 0;		//表示栈中以前存在的元素无效，再放新值时就覆盖掉
}

template <typename T>
int MyStack<T>::StackLength()
{
	return m_iTop;
}
		
//一定是放在栈顶.两种设计思路，一种是用throw抛出异常；一种返回布尔类型
//bool MyStack::push(Coordinate elem)
template <typename T>
bool MyStack<T>::push(T elem)
{
	if(StackFull())
	{
		return false;	
	}
	
	//这里只需做简单的值赋值。对计算机来说默认的拷贝构造函数
	//和默认的赋值运算符重载能满足条件，才能把m_iX 和 m_iY赋值
	//给另外一个对象的数据成员
	
	m_pBuffer[m_iTop] = elem;	
	m_iTop++;	//m_iTop总是指向一个空位置，下一个要入栈的位置
	return true;
}

//bool MyStack::pop(Coordinate &elem)
template <typename T>
bool MyStack<T>::pop(T &elem)
{
	if(StackEmpty())
	{
		return false;
	}
	--m_iTop;	//使栈顶指向一个有元素的位置
	//如果刚刚有入栈操作，那么栈顶指向的是一个空的位置！！
	elem = m_pBuffer[m_iTop];
	return true;
}
		
//void MyStack::StackTraverse(visit())
//有些是这样的写法，当我们的栈不是简单元素栈，而是较为复杂的对象元素的栈时，
//就需要有这样一个专有的visit函数来访问栈中每一个对象元素
template <typename T>
void MyStack<T>::StackTraverse(bool isFromButtom)
{
	if(isFromButtom)
	{
		for(int i=0; i<m_iTop; i++)
		{
			//cout<<m_pBuffer[i]<<",";
			//m_pBuffer[i]这个栈里面每一个元素都是一个Coordinate对象,都调用自己的成员函数
			//m_pBuffer[i].printCoordinate();
			
			cout<<m_pBuffer[i];		//要求所有传入进来的所有的特殊的类，都对<<进行重载
		}
	}
	//m_iTop就是栈的长度

	else
	{
		for(int i=m_iTop-1; i>=0; i--)
		{
			//cout<<m_pBuffer[i]<<",";
			//m_pBuffer[i].printCoordinate();
			
			cout<<m_pBuffer[i];
		}
	}
	
}







