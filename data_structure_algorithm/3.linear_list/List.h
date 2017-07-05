#ifndef LIST_H
#define	LIST_H
/*
		���Ա�-------˳���
		3 5 7 2 9 1 8
		
C��ʽ��
bool InitList(List **list);
void DestoryList(List *list);
void ClearList(List *list);
bool ListEmpty(List *list);
int ListLength(List *list);
bool GetElem(List *list, int i, Elem *e);	//��������˳���i��ʾ������±�
int LocateElem(List *list, Elem *e);		//Ѱ�ҵ�һ������e������Ԫ�ص�λ��
bool PriorElem(List *list,Elem *currentElem, Elem *preElem);	//���ָ��Ԫ�ص�ǰ��
bool NextElem(List *list,Elem *currentElem, Elem *nextElem);	//���ָ��Ԫ�صĺ��
bool ListInset(List *list, int i, Elem *e);		//�ڵ�i��λ�ò���Ԫ��
bool ListDelete(List *list,int i, Elem *e);		//ɾ����i��λ��Ԫ��
void ListTraverse(List *list);
*/

#include "Coordinate.h"
class List
{
	public:
		//��Ϊ����˵��thisָ����൱�ڴ���ȥ�ˣ������ﶼ����Ҫ��C����һ������List *list
		List(int size);
		~List();
		void ClearList();
		bool ListEmpty();
		int ListLength();
		//bool GetElem(int i, int *e);	int����ȫ���滻ΪCoordinate
		bool GetElem(int i, Coordinate *e);
		int LocateElem(Coordinate *e);
		bool PriorElem(Coordinate *currentElem, Coordinate *preElem);
		bool NextElem(Coordinate *currentElem, Coordinate *nextElem);
		bool ListInsert(int i, Coordinate *e);	
		bool ListDelete(int i, Coordinate *e);
		void ListTraverse();
	private:
		Coordinate *m_pList;	//ָ��һ���ڴ������洢���ǵ����Ա����飩
		int m_iSize;
		int m_iLength;
};


	
#endif