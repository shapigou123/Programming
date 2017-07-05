#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct Node
{
	int key;
	struct Node *next;
}Node;
typedef struct Node *linkList;


linkList FindKthToTail(linkList pHeader, int k)
{
	linkList p = pHeader;
	//k=0 或头结点为NULL的情况
	if(k == 0 ||pHeader == NULL)
	{
		return NULL;
	}
	linkList pAhead = pHeader;
	linkList pBehind = pHeader;
	for(int i=0; i<k; i++)
	{
		//判定k大于链表的节点总数的情况
		if(pAhead->next != NULL)
			pAhead=pAhead->next;
		else
			return NULL;
	}
	while(pAhead->next != NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
	
}

int main()
{
	int n;
	cin>>n;
	
	linkList pHead=(linkList)malloc(sizeof(struct Node));//定义单链表头指针
	linkList p;
	linkList q = NULL;
	p=pHead;

	//依次输入链表节点值
	for(int i=0;i<n;i++)
	{
		cin>>p->key;
		//p->key=i;
		p->next=(linkList)malloc(sizeof(struct Node));
		p=p->next;
	}
	p->next=NULL;//尾指针为空

	//输入倒数第k个数（k可以为0）
	int k;
	cin>>k;
	
	q = FindKthToTail(pHead,k);
	
	if(q == NULL)
		return -1;
	cout<<q->key<<endl;

	return 0;
}