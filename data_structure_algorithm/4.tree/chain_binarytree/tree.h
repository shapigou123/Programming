#ifndef TREE_H
#define TREE_H
	
#include "tree.h"
#include "node.h"
class Tree
{
	public:
		//要在建立树之初，就有一个根节点，以后才好插入
		//pRoot就是整个树的根节点
		Tree();		
		~Tree();
		//最基础的，删除、添加都要用到这个
		Node *SearchNode(int nodeIndex);
		//指定索引，将要插入的节点挂接在指定节点上，并指定方向
		bool AddNode(int nodeIndex, int direction, Node *pNode);	
		//将要删除的节点放入pNode中
		bool DeleteNode(int nodeIndex, Node *pNode);
		void PreorderTraverse();	//前序遍历
		void InorderTraverse();		//中序遍历
		void PostorderTreeTraverse(); 	//后序遍历
		
	private:
		/*  节点要素：
			索引	数据	左孩子指针	右孩子指针  父节点指针（找父节点）
			
							*(0)
							
					5(1)			8(2)
					
				2(3)	6(4)	9(5)	 7(6)
					
			前序遍历（根左右）：	0 1 3 4 2 5 6
			中序遍历（左根右）：	3 1 4 0 5 2 6
			后序遍历（左右根）：	3 4 1 5 6 2 0
			
		*/
		//树的根节点
		Node *m_pRoot;
};	
	
#endif