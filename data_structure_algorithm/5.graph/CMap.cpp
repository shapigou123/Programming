#include "CMap.h"
#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	//顶点数组
	m_pNodeArray = new Node[m_iCapacity];
	//邻接矩阵
	m_pMatrix = new	int[m_iCapacity * m_iCapacity];
	memset(m_pMatrix, 0, m_iCapacity*m_iCapacity*sizeof(int));
}

CMap::~CMap()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
	m_pMatrix = NULL;
	m_pNodeArray = NULL;
}

//向图中加入顶点
bool CMap::addNode(Node *pNode)
{
	//顶点的索引就是m_pNodeArray数组的下标
	//m_iNodeCount初始值为0
	if(pNode == NULL)
		return false;
	m_pNodeArray[m_iNodeCount].m_cDate = pNode->m_cDate;
	m_iNodeCount++;
}

//重置顶点
void CMap::resetNode()
{
	for(int i=0; i<m_iNodeCount; i++)
		m_pNodeArray[i].m_bIsVisited = false;	
}

//为有向图设置邻接矩阵
//其实就是进行边的设置
bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= m_iCapacity)
		return false;
	if(col < 0 || col >= m_iCapacity)
		return false;

	m_pMatrix[row*m_iCapacity + col] = val;
	return true;
}

//为无向图设置邻接矩阵
bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= m_iCapacity)
		return false;
	if(col < 0 || col >= m_iCapacity)
		return false;

	m_pMatrix[row*m_iCapacity + col] = val;
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}
	
//打印邻接矩阵
void CMap::printMatix()
{
	for(int i=0; i<m_iCapacity; i++)
	{
		for(int k=0; k<m_iCapacity; k++)
		{
			cout << m_pMatrix[i*m_iCapacity+k] << " ";
		}
		cout<<endl;
	}
		
}

//深度优先遍历
void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;

	cout << m_pNodeArray[nodeIndex].m_cDate << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	//通过邻接矩阵判断是否与其他的顶点有连接
	for(int i=0; i<m_iCapacity; i++)
	{
		//判断nodeIndex和i是否相连接，取出了弧
		getValueFromMatrix(nodeIndex, i, value);
		if(value != 0)//判断有弧连接其他顶点
		{
			//在判断该点是否被访问过
			if(m_pNodeArray[i].m_bIsVisited)
				continue;
			else
				depthFirstTraverse(i);
		}
		else//如果没有去向索引为i的顶点的弧，则循环继续
			continue;
	}

}

//广度优先遍历
void CMap::breadthFirstTraverse(int nodeIndex)
{

	cout << m_pNodeArray[nodeIndex].m_cDate << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	//保存节点索引即可
	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImpl(curVec);

}

//广度优先遍历
void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	int value = 0;
	//用来保存当前这一层的所有节点
	vector<int> curVec;
	//preVec就是上一层的节点
	for(int i=0; i<preVec.size(); i++)
	{
		//判断上一层的节点与其他节点是否还有连接
		for(int j=0; j<m_iCapacity; j++)
		{
			getValueFromMatrix(preVec[i],j,value);
			if(value != 0)
			{
				if(m_pNodeArray[j].m_bIsVisited)
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[j].m_cDate<<" ";
					m_pNodeArray[j].m_bIsVisited = true;
					//加入到本层
					curVec.push_back(j);
				}

			}
		}
	}

	if(curVec.size() == 0)
	{
		return;
	}
	else
	{
		breadthFirstTraverseImpl(curVec);
	}

}

//从矩阵中获取值
//val为0，顶点不相连
bool CMap::getValueFromMatrix(int row, int col, int &val)
{
	if(row < 0 || row >= m_iCapacity)
		return false;
	if(col < 0 || col >= m_iCapacity)
		return false;

	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}	

