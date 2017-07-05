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
	
							*(0)
							
					5(1)			8(2)
					
				2(3)	6(4)	9(5)	 7(6)
	
	
	*/
	
int main(void)
{
	 //新建树的时候，就通过Tree的构造函数建立了一个根节点

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

	
	
	//刚建立树并插入节点的时候，要指定一个有效的索引
	pTree->AddNode(0,0,node1);
	pTree->AddNode(0,1,node2);
	pTree->AddNode(1,0,node3);
	pTree->AddNode(1,1,node4);
	pTree->AddNode(2,0,node5);
	pTree->AddNode(2,1,node6);
	
	
	// int *p = pTree->SearchNode(2);
	// cout<<"SearchNode: "<<*p<<endl;
	
	// int temp = 0;
	
	//删除节点失效！1.-->插入节点有问题
	//2.-->搜索节点发生错误，也可能导致删除节点出现问题
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


















