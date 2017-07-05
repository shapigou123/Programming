#include<iostream>
#include "tree.h"
using namespace std;

	/* 
	�������ʾ�Ķ�������
	1.���Ĵ���������
	2.���нڵ������
	3.���нڵ����Ӻ�ɾ��
	4.���нڵ�ı�����û��ǰ���������

	bool CreatTree(Node *pRoot);		���캯��
	void DestoryTree();		��������
	Node *SearchNode*(int nodeIndex);
	
	ָ�����������ڸ��ڵ���˵����Ҫ��ӵ������ӻ����Һ��ӡ��Լ�Ҫ��ӵĽڵ�
	bool AddNode(int nodeIndex, int direction, Node *pNode);	
	bool DeleteNode(int nodeIndex, Node *pNode);
	void TreeTraverse(); 

	*/
	
int main(void)
{
	//�ոս�������ʱ������û��������Ľڵ�
	int root = 3;
	Tree *pTree = new Tree(10, &root);
	
	int node1 = 5;
	int node2 = 8;
	int node3 = 2;
	int node4 = 6;
	int node5 = 9;
	int node6 = 7;
	//�ս�����������ڵ��ʱ��Ҫָ��һ����Ч������
	pTree->AddNode(0,0,&node1);
	pTree->AddNode(0,1,&node2);
	pTree->AddNode(1,0,&node3);
	pTree->AddNode(1,1,&node4);
	pTree->AddNode(2,0,&node5);
	pTree->AddNode(2,1,&node6);
	
	
	int *p = pTree->SearchNode(2);
	cout<<"SearchNode: "<<*p<<endl;
	
	int temp = 0;
	pTree->DeleteNode(0, &temp);
	cout<<"DeleteNode: "<<temp<<endl;
	
	pTree->TreeTraverse();
	return 0;
	
}


















