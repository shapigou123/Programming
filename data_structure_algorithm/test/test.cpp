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
	//k=0 ��ͷ���ΪNULL�����
	if(k == 0 ||pHeader == NULL)
	{
		return NULL;
	}
	linkList pAhead = pHeader;
	linkList pBehind = pHeader;
	for(int i=0; i<k; i++)
	{
		//�ж�k��������Ľڵ����������
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
	
	linkList pHead=(linkList)malloc(sizeof(struct Node));//���嵥����ͷָ��
	linkList p;
	linkList q = NULL;
	p=pHead;

	//������������ڵ�ֵ
	for(int i=0;i<n;i++)
	{
		cin>>p->key;
		//p->key=i;
		p->next=(linkList)malloc(sizeof(struct Node));
		p=p->next;
	}
	p->next=NULL;//βָ��Ϊ��

	//���뵹����k������k����Ϊ0��
	int k;
	cin>>k;
	
	q = FindKthToTail(pHead,k);
	
	if(q == NULL)
		return -1;
	cout<<q->key<<endl;

	return 0;
}