#include "MyQueue.h"
#include "Customer.h"
#include <iostream>
using namespace std;

MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	//m_pQueue = new int[m_iQueueCapacity];
	m_pQueue = new Customer[m_iQueueCapacity];
	ClearQueue();
}

MyQueue::~MyQueue()
{
	delete []m_pQueue;
	m_pQueue = NULL;
	
}

//清空队列，内存还保存着，元素都不在了，对头队尾恢复到了初始位置
void MyQueue::ClearQueue()	
{
	m_iTail	= 0;
	m_iHead = 0;
	m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty() const
{
	if(m_iQueueLen == 0)
		return true;
	else
		return false;
	//return m_iQueueLen == 0?true:false;
}

bool MyQueue::QueueFull() const
{
	if(m_iQueueLen == m_iQueueCapacity)
		return true;
	else
		return false;
}

int MyQueue::QueueLength() const
{
	return m_iQueueLen;
}

//插入一个元素，队尾移动一格
//bool MyQueue::EnQueue(int element)
bool MyQueue::EnQueue(Customer element)
{
	if(QueueFull())
		return false;
	else
	{
		m_pQueue[m_iTail] = element;	//直接赋值，不需要考虑深拷贝浅拷贝
		m_iTail++;
		m_iTail = m_iTail%m_iQueueCapacity;	//防止数组越界，当插满了之后应该指向0
		m_iQueueLen++;
	//	m_iTail
		return true;
	}
}

//出队时，队列头往后移动一格
//bool MyQueue::DeQueue(int &element)
bool MyQueue::DeQueue(Customer &element)
{
	if(QueueEmpty())
		return false;
	else
	{
		element = m_pQueue[m_iHead];	//出队，将队头所指向的元素赋给传进来的参数
		m_iHead++;
		m_iHead = m_iHead%m_iQueueCapacity;
		m_iQueueLen--;
		return true;
		
	}
}

void MyQueue::QueueTraverse()
{
	for(int i=m_iHead; i<m_iQueueLen+m_iHead; i++)	//保证循环次数不会出错
	{
		//cout<<m_pQueue[i%m_iQueueCapacity]<<endl;
		m_pQueue[i%m_iQueueCapacity].printInfo();
		cout<<"前面还有："<<(i-m_iHead)<<"人"<<endl;
	}
}












