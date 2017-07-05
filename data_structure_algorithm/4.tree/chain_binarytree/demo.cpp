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
	
							*(0)
							
					5(1)			8(2)
					
				2(3)	6(4)	9(5)	 7(6)
	
	
	*/
	
int main(void)
{
	 //�½�����ʱ�򣬾�ͨ��Tree�Ĺ��캯��������һ�����ڵ�

	Tree *pTree = new Tree();
	
	Node *node1 = new Node();
	Node *node2 = new Node();
	Node *node3 = new Node();
	Node *node4 = new Node();
	Node *node5 = new Node();
	Node *node6 = new Node();
	
	node1->index = 1;
	node1->data = 5;
	
	node2->index = 2;
	node2->data = 8;
	
	node3->index = 3;
	node3->data = 2;
	
	node4->index = 4;
	node4->data = 6;
	
	node5->index = 5;
	node5->data = 9;
	
	node6->index = 6;
	node6->data = 7;

	
	
	//�ս�����������ڵ��ʱ��Ҫָ��һ����Ч������
	pTree->AddNode(0,0,node1);
	pTree->AddNode(0,1,node2);
	pTree->AddNode(1,0,node3);
	pTree->AddNode(1,1,node4);
	pTree->AddNode(2,0,node5);
	pTree->AddNode(2,1,node6);
	
	
	// int *p = pTree->SearchNode(2);
	// cout<<"SearchNode: "<<*p<<endl;
	
	// int temp = 0;
	
	//ɾ���ڵ�ʧЧ��1.-->����ڵ�������
	//2.-->�����ڵ㷢������Ҳ���ܵ���ɾ���ڵ��������
	// pTree->DeleteNode(6, NULL);
	 // pTree->DeleteNode(5, NULL);
	   pTree->DeleteNode(0, NULL);
	// cout<<"DeleteNode: "<<temp<<endl;

	pTree->PreorderTraverse();
	//pTree->InorderTraverse();
	//pTree->PostorderTreeTraverse();
	delete pTree;
	pTree = NULL;
	return 0;
	
}


















