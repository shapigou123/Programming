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
	//判断当前是不是要找的节点
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
		//没找到时也要进行处理，以前忘记处理了
		//没找到也要继续向下找，让左右继续调用当前函数进行寻找
		else
		{
			temp = this->pLChild->SearchNode(nodeIndex);
			//不为NULL，就找到了，并返回
			//为NULL，就继续从右边找
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
			//不管找到与否都直接return
			if(temp != NULL)
				return temp;
		}
	}
	
	return NULL;
	
}


//1.对于Node来说，要删除自己，首先要删除自己所有的子节点
//2.同时要看自己是处于上一层节点的左位置还是右位置
//3.如果为左位置，就让父节点的左孩子指针指为NULL；
//4.如果为右位置，就让父节点的右孩子指针指为NULL；
//5.然后自己再自杀

void Node::DeleteNode()
{
	//删除左右孩子节点
	//this 用来描述当前对象

	if(this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();
	}
	
	if(this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();
	}
	
	//找到父节点指针
	//我们能全部打印出来，说明找父节点的时候出现了问题
	if(this->pParent != NULL)
	{
		//当前节点挂载在它父节点的左边
		//父亲节点没有找到的话，就没有办法给父节点的左右孩子指针赋值NULL
		//没有找到父亲节点，原因出在插入节点上
		if(this->pParent->pLChild == this)
		{
			
			this->pParent->pLChild = NULL;
		}
		//当前节点挂载在它父节点的右边
		if(this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}	
		
	}

	delete this;
	
}

//前序遍历：根左右。
//递归访问左节点，就变成了访问左子树，递归访问右节点就变成了访问右子树
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

//采用递归调用
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





