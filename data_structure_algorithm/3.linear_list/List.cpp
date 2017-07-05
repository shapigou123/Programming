#include "List.h"
#include "Coordinate.h"
#include <iostream>
using namespace std;


List::List(int size)
{
	m_iSize = size;
	//m_pList = new int[m_iSize];
	m_pList = new Coordinate[m_iSize];
	m_iLength = 0;
	
}

List::~List()
{
	delete []m_pList;
	m_pList	= NULL;		
}

//清空当前线性表，但不意味着释放当前线性表的内存
//已经在线性表中存在的值可以忽略，因为后面往里面放值时可以直接覆盖
void List::ClearList()
{
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

bool List::GetElem(int i, Coordinate *e)
{
	if(i<0 || i>=m_iLength)
		return false;
	*e = m_pList[i];
	return true;
}

int List::LocateElem(Coordinate *e)
{
	for(int i=0; i<m_iLength; i++)
	{
		if(m_pList[i] == *e)
		{
			return i;
		}
	}
	return -1;
}

bool List::PriorElem(Coordinate *currentElem, Coordinate *preElem)
{
//	if(ListEmpty())
//		return false;
	int temp = LocateElem(currentElem);
	if(-1 == temp )
	{
		return false;
	}
	else
	{
		if(0 == temp)
		{
			return false;
		}
		else
		{
			*preElem = m_pList[temp-1];
			return true;
		}			
	}
}

bool List::NextElem(Coordinate *currentElem, Coordinate *nextElem)
{
//	if(ListEmpty())
//		return false;
	
	int temp = LocateElem(currentElem);
	if(-1 == temp )
	{
		return false;
	}
	else
	{
		if(m_iLength-1 == temp)
		{
			return false;
		}
		else
		{
			*nextElem = m_pList[temp+1];
			return true;
		}			
	}	
}

//涉及到元素的移动
bool List::ListInsert(int i, Coordinate *e)
{
	if(i<0 || i>m_iLength)
		return false;
	//先把最后一个元素往后移动
	for(int k=m_iLength-1; k>=i; k--)
	{
		m_pList[k+1] = m_pList[k];
	}
	
	//i=m_iLength时，跳过循环，直接走这条路
	m_pList[i] = *e;
	m_iLength++;
	return true;
	
}

//先删除再移动
bool List::ListDelete(int i, Coordinate *e)
{
	if(i<0 || i>=m_iLength)
		return false;
	
	*e = m_pList[i];
	//先移动前面的元素
	for(int k=i+1; k<m_iLength; k++)
	{
		m_pList[k-1] = m_pList[k];
	}
	
	m_iLength--;
	return true;
}
void List::ListTraverse()
{
	if(ListEmpty())
		return;
	for(int i=0; i<m_iLength; i++)
	{
		cout<<m_pList[i]<<endl;
		//m_pList[i].printCoordinate();
	}
	
}






