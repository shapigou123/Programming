#include<iostream>
#include "tree.h"
using namespace std;

	/* 
	用数组表示的二叉树：
	1.树的创建和销毁
	2.树中节点的搜索
	3.树中节点的添加和删除
	4.树中节点的遍历（没有前序中序后序）

	bool CreatTree(Node *pRoot);		构造函数
	void DestoryTree();		析构函数
	Node *SearchNode*(int nodeIndex);
	
	指定索引（对于根节点来说）、要添加的是左孩子还是右孩子、以及要添加的节点
	bool AddNode(int nodeIndex, int direction, Node *pNode);	
	bool DeleteNode(int nodeIndex, Node *pNode);
	void TreeTraverse(); 

	*/
	
int main(void)
{
	//刚刚建立树的时候，其中没有有意义的节点
	int root = 3;
	Tree *pTree = new Tree(10, &root);
	
	int node1 = 5;
	int node2 = 8;
	int node3 = 2;
	int node4 = 6;
	int node5 = 9;
	int node6 = 7;
	//刚建立树并插入节点的时候，要指定一个有效的索引
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


















