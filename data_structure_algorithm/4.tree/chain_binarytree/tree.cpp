#include <iostream>
#include "tree.h"
#include "node.h"
using namespace std;


Tree::Tree()
{
	//不在树的第一个节点放有意义的值，故直接调用Node的构造函数即可
	m_pRoot = new Node();
}
		
Tree::~Tree()
{
	//直接删除根节点即可，也不需要去任何节点
	DeleteNode(0,NULL);
	//这种写法也可以，但是树的数据成员不止m_pRoot,还有其他数据成员，并且是指针，而且在
	//构造函数中申请了内存，那么仅仅使用m_pRoot->DeleteNode()是不够的
	//m_pRoot->DeleteNode();也可
}

//在树的这个层次去寻找节点，还需要考虑节点的左右两个孩子（以及他们本身的左右孩子）
//同时也无法确定有多少层。我们可以把这个任务归给下一层的类，即Node这个类来完成
Node *Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}


//direction = 0,往左边插入
//nodeIndex表示往哪个节点插入节点
//pNode要插入的节点
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	//第一步：找到节点
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
	
	//如果直接将pNode挂载在树的节点下，pNode作为外面传进来的数据如果被外面的函数
	//或者其他语句修改的话，那么它的完整性就不存在了。对树的影响也很大。
	Node *node = new Node();
	if(node == NULL)
	{
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;
	
	//这里我们插入时只是给左右孩子节点放上了相应的值
	//并没有在插入的时候将node这个值的父节点指定出来！！
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


//删除节点，并把节点的内容拷贝给pNode
//在树中，除了要删除该节点，还要删除该节点所有的子节点
bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	//第一步：找到节点
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
	
	//如果找到要删除的节点，则将要删除的节点先放在pNode中，然后再删除
	//若pNode不为NULL，就需要做取的工作
	//若pNode本身就为NULL，就不用做取的工作，只做删除节点即可

	if(pNode != NULL)
	{
		pNode->data = temp->data;
	}
	
	//删除节点，在树的层级上不容易做，我们回到Node这个级别
	temp->DeleteNode();
	return true;
	
}



//也在节点中实现
void Tree::PreorderTraverse()	//前序遍历
{
	//调用Node的成员函数
	m_pRoot->PreorderTraverse();
	
}

void Tree::InorderTraverse()	//中序遍历
{
	m_pRoot->InorderTraverse();
}

void Tree::PostorderTreeTraverse()	//后序遍历
{
	m_pRoot->PostorderTreeTraverse();
	
}



	

	





