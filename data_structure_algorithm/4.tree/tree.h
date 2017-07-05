#ifndef TREE_H
#define TREE_H
	
class Tree
{
	public:
		//要在建立树之初，就有一个根节点，以后才好插入
		//pRoot就是整个树的根节点
		Tree(int size, int *pRoot);		
		~Tree();
		int *SearchNode(int nodeIndex);
		bool AddNode(int nodeIndex, int direction, int *pNode);	
		bool DeleteNode(int nodeIndex, int *pNode);
		void TreeTraverse(); 
	private:
		int *m_pTree;	//将来指向数组，在构造函数中分配，析构函数中释放
		int m_iSize;	//记录数组的大小
};	
	
#endif