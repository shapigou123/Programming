#ifndef SINGLE_LIST_H
#define	SINGLE_LIST_H
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


#include "Node.h"
class List
{
	public:
		//��Ϊ����˵��thisָ����൱�ڴ���ȥ�ˣ������ﶼ����Ҫ��C����һ������List *list
		//���캯�����ȷ�һ��ͷ��㣬�����Ϳ���ͨ����ͷ�������������
		
		//����������˵��ÿ����һ���ڵ㣬ֻ��Ҫ�ڶ�����ʱ����һ���ڴ�
		List();
		
		//�������Ҫ��������е�ÿһ���ڵ�
		~List();
		void ClearList();
		bool ListEmpty();
		int ListLength();
		//bool GetElem(int i, int *e);	int����ȫ���滻ΪCoordinate
		
		//Ҫ���õ�ͷ��㣬Ȼ�����ΰ����ҵ���i��λ���õ���Ӧ���ݷŵ�Elem��
		bool GetElem(int i, Node *e);
		
		int LocateElem(Node *e);
		//ͬ��Ҫʹ��ͷ��������
		bool PriorElem(Node *pCurrentNode, Node *pPreNode);
		bool NextElem(Node *pCurrentNode, Node *pNextNode);
	
		//�����ҵ�i-1��λ�õĽڵ㣬������ָ����ָ��pNode
		//pNodeָ����ָ��ԭ��i-1�ڵ���ָ��Ľڵ�
		bool ListInsert(int i, Node *pNode);	
		
		//�ҵ�Ҫɾ����λ�õ���һ���ڵ�i-1��λ�õĽڵ㣬
		//������ָ����ָ��Ҫɾ���ڵ��ָ������ָ��Ľڵ�
		bool ListDelete(int i, Node *pNode);
		
		//����ͷ���ĺ���
		bool ListInsertHead(Node *pNode);	
		bool ListInsertTail(Node *pNode);
		
		//��Ҫ����ͷ��㣬��ÿһ���ڵ���˳����ʣ�ֱ�����ʵ�β�ڵ�
		void ListTraverse();
	private:
		Node *m_pList;	//ָ��һ���ڴ������洢���ǵ����Ա����飩
		//int m_iSize;
		int m_iLength;
};


	
#endif