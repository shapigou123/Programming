#ifndef __MYQUEQU_H__
#define	__MYQUEQU_H__

#include "Customer.h"
class MyQueue
{
	public:
		MyQueue(int queueCapacity);		//InitQueue(&Q) ��������(����Ϊ����)
		virtual ~MyQueue();				//DestoryQueue(&Q)���ٶ���
		void ClearQueue();				//ClearQueue(&Q)��ն��С�����Ҫ��������ͨ���Լ������ݳ�Ա�������
		bool QueueEmpty() const;		//QueueEmpty(Q)�пն��С��ж�m_pQueueָ��ָ��������Ƿ�Ϊ��
		bool QueueFull() const;
		int QueueLength() const;		//QueueLength(Q)���г���
		//bool EnQueue(int element);		//EnQueue(&Q, element)��Ԫ�����
		//bool DeQueue(int &element);		//DeQueue(&Q, &element)��Ԫ�س���	
		bool EnQueue(Customer element);		
		bool DeQueue(Customer &element);
		void QueueTraverse();			//QueueTraverse(Q��visit())��������
		
	private:
		//int *m_pQueue;	
		Customer *m_pQueue;
										//��������ָ�롣�����Ǽ��������ͣ����Խ�ÿ��Ԫ��
										//����һ��class������Ķ���ÿ������ķ��ʷ�����ͬ��
										//��Ҫ�ڱ������е�ʱ������ʶ���ķ���
		int m_iQueueLen;				//����Ԫ�ظ���
		int m_iQueueCapacity;			//������������
		int m_iHead;					//��������ʵ�ֶ��У��������ʾ������±�
		int m_iTail;
};

#endif