#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct ListNode
{
      int       m_nKey;
      struct ListNode* m_pNext;
};

struct ListNode * creat_node(int data)
{
	//struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *p = new (struct ListNode);
	if(NULL == p)
	{
		return NULL;
	}
	
	bzero(p,sizeof(struct ListNode));
	p->m_nKey = data;
	p->m_pNext = NULL;
	return p;
}

void insert_tail(struct ListNode *pHeader, struct ListNode *newnode)
{
	struct ListNode *p = pHeader;
	
	while(NULL != p->m_pNext)
	{
		p = p->m_pNext;
	}
	p->m_pNext = newnode;
}

void insert_head(struct ListNode *pHeader, struct ListNode *newnode)
{

	newnode->m_pNext=pHeader->m_pNext;
    pHeader->m_pNext = newnode;
}


void list_for_each(struct ListNode *pHeader)
{
	struct ListNode *p = pHeader;
	while(p->m_pNext != NULL)
	{
		p = p->m_pNext;
		cout<<p->m_nKey<<" ";
	}
	
}

int list_for_key1(struct ListNode *pHeader, int num, int k)
{
	struct ListNode *p = pHeader;
	if(k>num)
		return -1;
	if(p->m_pNext != NULL)
	{
		p = p->m_pNext;
		for(int i=0;i<k-1; i++)
			p = p->m_pNext;
		
		return p->m_nKey;
	} 
	else 
		return -1;
}

int list_for_key(struct ListNode *pHeader, int num, int k)
{
	struct ListNode *p = pHeader;
	if(k<num)
		return -1;
	if(p->m_pNext != NULL)
	{
		p = p->m_pNext;
		for(int i=0;i<num-k; i++)
			p = p->m_pNext;
		
		return p->m_nKey;
	} 
	return -1;
}

ListNode* FindKthToTail(ListNode * pHeader, int k)
{
	struct ListNode *p = pHeader;
	//k=0 或头结点为NULL的情况
	if(k == 0 || pHeader == NULL)
	{
		return NULL;
	}
	ListNode *pAhead = pHeader;
	ListNode *pBehind = pHeader;
	for(int i=0; i<k-1; i++)
	{
		//判定k大于链表的节点总数的情况
		if(pAhead->m_pNext != NULL)
			pAhead=pAhead->m_pNext;
		else
			return NULL;
	}
	while(pAhead->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
	
}

int main(void)
{
    int NodeNum;
	int inputData;
	int K;
	struct ListNode *ListHeader = creat_node(K);
   // struct ListNode *ListHeader = NULL;
	struct ListNode *p = NULL;
	cin>>NodeNum;
	for(int i=0; i<NodeNum; i++)
	{
		cin>>inputData;
		//if(i = 0)
			//ListHeader = creat_node(inputData);
		//else
			insert_tail(ListHeader, creat_node(inputData));
	}

	cin>>K;
	if(K>NodeNum)
		return -1;
	p = FindKthToTail(ListHeader,K);
	if(p == NULL)
		return -1;
	cout<<p->m_nKey<<endl;
    return 0;
}










