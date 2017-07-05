#include <iostream>
#include "tree.h"
#include "node.h"
using namespace std;


Tree::Tree()
{
	//�������ĵ�һ���ڵ���������ֵ����ֱ�ӵ���Node�Ĺ��캯������
	m_pRoot = new Node();
}
		
Tree::~Tree()
{
	//ֱ��ɾ�����ڵ㼴�ɣ�Ҳ����Ҫȥ�κνڵ�
	DeleteNode(0,NULL);
	//����д��Ҳ���ԣ������������ݳ�Ա��ֹm_pRoot,�����������ݳ�Ա��������ָ�룬������
	//���캯�����������ڴ棬��ô����ʹ��m_pRoot->DeleteNode()�ǲ�����
	//m_pRoot->DeleteNode();Ҳ��
}

//������������ȥѰ�ҽڵ㣬����Ҫ���ǽڵ�������������ӣ��Լ����Ǳ�������Һ��ӣ�
//ͬʱҲ�޷�ȷ���ж��ٲ㡣���ǿ��԰������������һ����࣬��Node����������
Node *Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}


//direction = 0,����߲���
//nodeIndex��ʾ���ĸ��ڵ����ڵ�
//pNodeҪ����Ľڵ�
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	//��һ�����ҵ��ڵ�
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
	
	//���ֱ�ӽ�pNode���������Ľڵ��£�pNode��Ϊ���洫�������������������ĺ���
	//������������޸ĵĻ�����ô���������ԾͲ������ˡ�������Ӱ��Ҳ�ܴ�
	Node *node = new Node();
	if(node == NULL)
	{
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;
	
	//�������ǲ���ʱֻ�Ǹ����Һ��ӽڵ��������Ӧ��ֵ
	//��û���ڲ����ʱ��node���ֵ�ĸ��ڵ�ָ����������
	if(direction == 0)
	{	
		temp->pLChild = node;
	}
	
	if(direction == 1)
	{
		temp->pRChild = node;
	}
	
	return true;
}


//ɾ���ڵ㣬���ѽڵ�����ݿ�����pNode
//�����У�����Ҫɾ���ýڵ㣬��Ҫɾ���ýڵ����е��ӽڵ�
bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	//��һ�����ҵ��ڵ�
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
	
	//����ҵ�Ҫɾ���Ľڵ㣬��Ҫɾ���Ľڵ��ȷ���pNode�У�Ȼ����ɾ��
	//��pNode��ΪNULL������Ҫ��ȡ�Ĺ���
	//��pNode�����ΪNULL���Ͳ�����ȡ�Ĺ�����ֻ��ɾ���ڵ㼴��

	if(pNode != NULL)
	{
		pNode->data = temp->data;
	}
	
	//ɾ���ڵ㣬�����Ĳ㼶�ϲ������������ǻص�Node�������
	temp->DeleteNode();
	return true;
	
}



//Ҳ�ڽڵ���ʵ��
void Tree::PreorderTraverse()	//ǰ�����
{
	//����Node�ĳ�Ա����
	m_pRoot->PreorderTraverse();
	
}

void Tree::InorderTraverse()	//�������
{
	m_pRoot->InorderTraverse();
}

void Tree::PostorderTreeTraverse()	//�������
{
	m_pRoot->PostorderTreeTraverse();
	
}



	

	





