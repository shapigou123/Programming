#ifndef __MYQUEQU_H__
#define	__MYQUEQU_H__

#include "Customer.h"
class MyQueue
{
	public:
		MyQueue(int queueCapacity);		//InitQueue(&Q) 创建队列(参数为容量)
		virtual ~MyQueue();				//DestoryQueue(&Q)销毁队列
		void ClearQueue();				//ClearQueue(&Q)清空队列。不需要传参数，通过自己的数据成员就能完成
		bool QueueEmpty() const;		//QueueEmpty(Q)判空队列。判断m_pQueue指针指向的数组是否为空
		bool QueueFull() const;
		int QueueLength() const;		//QueueLength(Q)队列长度
		//bool EnQueue(int element);		//EnQueue(&Q, element)新元素入队
		//bool DeQueue(int &element);		//DeQueue(&Q, &element)首元素出队	
		bool EnQueue(Customer element);		
		bool DeQueue(Customer &element);
		void QueueTraverse();			//QueueTraverse(Q，visit())遍历队列
		
	private:
		//int *m_pQueue;	
		Customer *m_pQueue;
										//队列数组指针。这里是简单数据类型，可以将每个元素
										//看成一个class所定义的对象，每个对象的访问方法不同，
										//需要在遍历队列的时候定义访问对象的方法
		int m_iQueueLen;				//队列元素个数
		int m_iQueueCapacity;			//队列数组容量
		int m_iHead;					//用数组来实现队列，故这里表示数组的下标
		int m_iTail;
};

#endif