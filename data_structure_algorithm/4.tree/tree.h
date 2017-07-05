#ifndef TREE_H
#define TREE_H
	
class Tree
{
	public:
		//Ҫ�ڽ�����֮��������һ�����ڵ㣬�Ժ�źò���
		//pRoot�����������ĸ��ڵ�
		Tree(int size, int *pRoot);		
		~Tree();
		int *SearchNode(int nodeIndex);
		bool AddNode(int nodeIndex, int direction, int *pNode);	
		bool DeleteNode(int nodeIndex, int *pNode);
		void TreeTraverse(); 
	private:
		int *m_pTree;	//����ָ�����飬�ڹ��캯���з��䣬�����������ͷ�
		int m_iSize;	//��¼����Ĵ�С
};	
	
#endif