#ifndef TREE_H
#define TREE_H
	
#include "tree.h"
#include "node.h"
class Tree
{
	public:
		//Ҫ�ڽ�����֮��������һ�����ڵ㣬�Ժ�źò���
		//pRoot�����������ĸ��ڵ�
		Tree();		
		~Tree();
		//������ģ�ɾ������Ӷ�Ҫ�õ����
		Node *SearchNode(int nodeIndex);
		//ָ����������Ҫ����Ľڵ�ҽ���ָ���ڵ��ϣ���ָ������
		bool AddNode(int nodeIndex, int direction, Node *pNode);	
		//��Ҫɾ���Ľڵ����pNode��
		bool DeleteNode(int nodeIndex, Node *pNode);
		void PreorderTraverse();	//ǰ�����
		void InorderTraverse();		//�������
		void PostorderTreeTraverse(); 	//�������
		
	private:
		/*  �ڵ�Ҫ�أ�
			����	����	����ָ��	�Һ���ָ��  ���ڵ�ָ�루�Ҹ��ڵ㣩
			
							*(0)
							
					5(1)			8(2)
					
				2(3)	6(4)	9(5)	 7(6)
					
			ǰ������������ң���	0 1 3 4 2 5 6
			�������������ң���	3 1 4 0 5 2 6
			������������Ҹ�����	3 4 1 5 6 2 0
			
		*/
		//���ĸ��ڵ�
		Node *m_pRoot;
};	
	
#endif