#ifndef SINGLE_LIST_H
#define	SINGLE_LIST_H
/*
		线性表-------顺序表
		3 5 7 2 9 1 8
		
C方式：
bool InitList(List **list);
void DestoryList(List *list);
void ClearList(List *list);
bool ListEmpty(List *list);
int ListLength(List *list);
bool GetElem(List *list, int i, Elem *e);	//用数组存放顺序表，i表示数组的下标
int LocateElem(List *list, Elem *e);		//寻找第一个满足e的数据元素的位序
bool PriorElem(List *list,Elem *currentElem, Elem *preElem);	//获得指定元素的前驱
bool NextElem(List *list,Elem *currentElem, Elem *nextElem);	//获得指定元素的后继
bool ListInset(List *list, int i, Elem *e);		//在第i个位置插入元素
bool ListDelete(List *list,int i, Elem *e);		//删除第i个位置元素
void ListTraverse(List *list);
*/


#include "Node.h"
class List
{
	public:
		//作为类来说，this指针就相当于传进去了，故这里都不需要像C语言一样传入List *list
		//构造函数中先放一个头结点，将来就可以通过该头结点来访问链表
		
		//对于链表来说，每增加一个节点，只需要在堆中临时申请一段内存
		List();
		
		//清空链表要清除链表中的每一个节点
		~List();
		void ClearList();
		bool ListEmpty();
		int ListLength();
		//bool GetElem(int i, int *e);	int类型全部替换为Coordinate
		
		//要先拿到头结点，然后依次挨个找到第i个位置拿到相应数据放到Elem中
		bool GetElem(int i, Node *e);
		
		int LocateElem(Node *e);
		//同样要使用头结点来完成
		bool PriorElem(Node *pCurrentNode, Node *pPreNode);
		bool NextElem(Node *pCurrentNode, Node *pNextNode);
	
		//首先找到i-1个位置的节点，让它的指针域指向pNode
		//pNode指针域指向原来i-1节点所指向的节点
		bool ListInsert(int i, Node *pNode);	
		
		//找到要删除的位置的上一个节点i-1个位置的节点，
		//让它的指针域指向要删除节点的指针域所指向的节点
		bool ListDelete(int i, Node *pNode);
		
		//插在头结点的后面
		bool ListInsertHead(Node *pNode);	
		bool ListInsertTail(Node *pNode);
		
		//需要拿着头结点，对每一个节点做顺序访问，直到访问到尾节点
		void ListTraverse();
	private:
		Node *m_pList;	//指向一块内存用来存储我们的线性表（数组）
		//int m_iSize;
		int m_iLength;
};


	
#endif