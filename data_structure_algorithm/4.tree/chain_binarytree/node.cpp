#include <iostream>
#include "node.h"
#include "tree.h"
using namespace std;

Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
	
}

Node *Node::SearchNode(int nodeIndex)
{
	//�жϵ�ǰ�ǲ���Ҫ�ҵĽڵ�
	if(this->index == nodeIndex)
	{
		return this;
	}
	
	Node *temp = NULL;
	if(this->pLChild != NULL)
	{
		if(this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}
		//û�ҵ�ʱҲҪ���д�����ǰ���Ǵ�����
		//û�ҵ�ҲҪ���������ң������Ҽ������õ�ǰ��������Ѱ��
		else
		{
			temp = this->pLChild->SearchNode(nodeIndex);
			//��ΪNULL�����ҵ��ˣ�������
			//ΪNULL���ͼ������ұ���
			if(temp != NULL)
				return temp;
		}
	}
	
	if(this->pRChild != NULL)
	{
		if(this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp = this->pRChild->SearchNode(nodeIndex);
			//�����ҵ����ֱ��return
			if(temp != NULL)
				return temp;
		}
	}
	
	return NULL;
	
}


//1.����Node��˵��Ҫɾ���Լ�������Ҫɾ���Լ����е��ӽڵ�
//2.ͬʱҪ���Լ��Ǵ�����һ��ڵ����λ�û�����λ��
//3.���Ϊ��λ�ã����ø��ڵ������ָ��ָΪNULL��
//4.���Ϊ��λ�ã����ø��ڵ���Һ���ָ��ָΪNULL��
//5.Ȼ���Լ�����ɱ

void Node::DeleteNode()
{
	//ɾ�����Һ��ӽڵ�
	//this ����������ǰ����

	if(this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();
	}
	
	if(this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();
	}
	
	//�ҵ����ڵ�ָ��
	//������ȫ����ӡ������˵���Ҹ��ڵ��ʱ�����������
	if(this->pParent != NULL)
	{
		//��ǰ�ڵ�����������ڵ�����
		//���׽ڵ�û���ҵ��Ļ�����û�а취�����ڵ�����Һ���ָ�븳ֵNULL
		//û���ҵ����׽ڵ㣬ԭ����ڲ���ڵ���
		if(this->pParent->pLChild == this)
		{
			
			this->pParent->pLChild = NULL;
		}
		//��ǰ�ڵ�����������ڵ���ұ�
		if(this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}	
		
	}

	delete this;
	
}

//ǰ������������ҡ�
//�ݹ������ڵ㣬�ͱ���˷������������ݹ�����ҽڵ�ͱ���˷���������
void Node::PreorderTraverse()
{
	cout<<this->index<<" "<<this->data<<endl;
	if(this->pLChild != NULL)
	{
		this->pLChild->PreorderTraverse();
	}
	
	if(this->pRChild != NULL)
	{
		this->pRChild->PreorderTraverse();
	}
	
}

//���õݹ����
void Node::InorderTraverse()
{
	
	if(this->pLChild != NULL)
	{
		this->pLChild->InorderTraverse();
	}
	
	cout<<this->index<<" "<<this->data<<endl;
	
	if(this->pRChild != NULL)
	{
		this->pRChild->InorderTraverse();
	}
}

void Node::PostorderTreeTraverse()
{
	if(this->pLChild != NULL)
	{
		this->pLChild->PostorderTreeTraverse();
	}
	
	if(this->pRChild != NULL)
	{
		this->pRChild->PostorderTreeTraverse();
	}
	
	cout<<this->index<<" "<<this->data<<endl;

}





