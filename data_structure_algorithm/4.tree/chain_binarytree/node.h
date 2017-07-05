#ifndef NODE_H
#define NODE_H


class Node
{
	public:
		Node();
		//node下面有一个，tree下面也有一个，他们是递归调用的。node被tree所调用
		Node *SearchNode(int nodeIndex);
		
		//删除节点时，已经没有寻找的过程了（找的工作由tree来完成了），故不需要nodeIndex
		
		void DeleteNode();
		void PreorderTraverse();
		void InorderTraverse();	
		void PostorderTreeTraverse();
		int data;
		int index;
		Node *pLChild;
		Node *pRChild;
		Node *pParent;
};




#endif