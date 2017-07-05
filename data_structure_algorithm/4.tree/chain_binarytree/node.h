#ifndef NODE_H
#define NODE_H


class Node
{
	public:
		Node();
		//node������һ����tree����Ҳ��һ���������ǵݹ���õġ�node��tree������
		Node *SearchNode(int nodeIndex);
		
		//ɾ���ڵ�ʱ���Ѿ�û��Ѱ�ҵĹ����ˣ��ҵĹ�����tree������ˣ����ʲ���ҪnodeIndex
		
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