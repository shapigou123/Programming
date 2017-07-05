#include "single_list.h"
#include "Node.h"
#include <iostream>
using namespace std;

//节点i 是从0开始！！

List::List()
{
	//m_iSize = size;
	//m_pList = new int[m_iSize];
	
	//首先定义一个头结点，通过它来操作链表
	m_pList = new Node;
	//m_pList->data = 0;
	m_pList->pNext = NULL;
	m_iLength = 0;
	
}

//将头结点也要清空

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}



//保留头结点，后面所有的节点都清空掉
void List::ClearList()
{
	Node *currentNode = m_pList->pNext;
	while(currentNode != NULL)
	{
		Node *temp = currentNode->pNext;	//保存下一个节点的地址
		delete currentNode;
		currentNode = temp;
	}
	m_pList->pNext = NULL;
	
	m_iLength = 0;
}

bool List::ListEmpty()
{
	if(0 == m_iLength)
		return true;
	else
		return false;
	//return m_iLength == 0 ? true : false;
}

int List::ListLength()
{
	return m_iLength;
}

//找到第i个节点，并将第i个节点的信息拷贝的pNode中
bool List::GetElem(int i, Node *pNode)
{
	if(i<0 || i>=m_iLength)
		return false;
		
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	
	//循环完后currentNode是第i个节点
	for(int k=0; k<=i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->pNext;
	}
	pNode->data = currentNode->data;
	return true;
}

//返回节点的索引
int List::LocateElem(Node *pNode)
{
	Node *currentNode = m_pList;
	int count = 0;
	while(currentNode->pNext != NULL)
	{
		currentNode = currentNode->pNext;
		if(currentNode->data == pNode->data)
		{
			return count;
		}
		count++;
	}
	return -1;

}


bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
//	if(ListEmpty())
//		return false;
	Node *currentNode = m_pList;
	Node *tempNode = NULL;

	while(currentNode->pNext != NULL)
	{
		tempNode = currentNode;	//在循环里保存currentNode上一个节点的位置
		currentNode = currentNode->pNext;
		if(currentNode->data == pCurrentNode->data)
		{
			//当找到的节点为第一个节点时，直接返回错误
			if(tempNode == m_pList)
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;
	
	while(currentNode->pNext != NULL)
	{
		currentNode = currentNode->pNext;
		if(currentNode->data == pCurrentNode->data)
		{
			//当找到的节点为最后一个节点时，直接返回错误
			if(currentNode->pNext == NULL)
			{
				return false;
			}
			pNextNode->data = currentNode->pNext->data;
			return true;
		}
	}
	return false;
}


//i = 0 ，不执行for循环，插入头结点后面
//i= m_iLength，通过for循环找到最后一个节点，newNode成为链表中最后一个节点
//在i-1个节点的后面插入（使其成为第i个位置节点）
bool List::ListInsert(int i, Node *pNode)
{
	if(i<0 || i>m_iLength)
		return false;
	//保存头结点
	Node *currentNode = m_pList;
	
	//找到的currentNode是第i个位置的上一个位置
	//用户传入0，不执行for循环
	//k = 0，
	for(int k=0; k<i; k++)
	{
		currentNode = currentNode->pNext;
	}
	
	Node *newNode = new Node;		//申请一个新的节点
	if(newNode == NULL)
		return false;
	
	newNode->data = pNode->data;
	newNode->pNext = currentNode->pNext;
	currentNode->pNext = newNode;
	m_iLength++;
	return true;
	
}

//先删除再移动
//若i=m_iLength，则删除的是尾节点的下一个节点，出错！
//删除的是第i个节点
bool List::ListDelete(int i, Node *pNode)
{
	//if(i<0 || i>m_iLength)
	if(i<0 || i>=m_iLength)
		return false;
	
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	
	//循环完后currentNode是第i个节点
	for(int k=0; k<=i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->pNext;
	}
	currentNodeBefore->pNext = currentNode->pNext;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}



bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->pNext;	//保存地址
	Node *newNode = new Node;		//申请一个新的节点
	if(newNode == NULL)
		return false;
	
	newNode->data = pNode->data;
	m_pList->pNext = newNode;
	newNode->pNext = temp;
	
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;	//保存地址
	while(currentNode->pNext != NULL)
	{
		currentNode = currentNode->pNext;
	}
	
	Node *newNode = new Node;		//申请一个新的节点
	if(newNode == NULL)
		return false;
	
	newNode->data = pNode->data;
	currentNode->pNext = newNode;
	newNode->pNext = NULL;
	m_iLength++;
	return true;
	
}
		
		
		
void List::ListTraverse()
{
	if(ListEmpty())
		return;
	Node *currentNode = m_pList;
	while(currentNode->pNext != NULL)
	{
		currentNode = currentNode->pNext;
		currentNode->printNode();
	}
}






