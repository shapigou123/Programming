#ifndef LIST_H
#define	LIST_H
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

#include "Coordinate.h"
class List
{
	public:
		//作为类来说，this指针就相当于传进去了，故这里都不需要像C语言一样传入List *list
		List(int size);
		~List();
		void ClearList();
		bool ListEmpty();
		int ListLength();
		//bool GetElem(int i, int *e);	int类型全部替换为Coordinate
		bool GetElem(int i, Coordinate *e);
		int LocateElem(Coordinate *e);
		bool PriorElem(Coordinate *currentElem, Coordinate *preElem);
		bool NextElem(Coordinate *currentElem, Coordinate *nextElem);
		bool ListInsert(int i, Coordinate *e);	
		bool ListDelete(int i, Coordinate *e);
		void ListTraverse();
	private:
		Coordinate *m_pList;	//指向一块内存用来存储我们的线性表（数组）
		int m_iSize;
		int m_iLength;
};


	
#endif