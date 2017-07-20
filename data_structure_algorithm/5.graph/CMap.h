#include <vector>
#include "node.h"
#include <string.h>
using namespace std;


class CMap
{
public:
	CMap(int capacity);
	~CMap();
	//向图中加入顶点
	bool addNode(Node *pNode);
	//重置顶点
	void resetNode(); 
	//为有向图设置邻接矩阵
	bool setValueToMatrixForDirectedGraph(int row, int col, int val=1);
	//为无向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1);
	
	//打印邻接矩阵
	void printMatix();

	//深度优先遍历
	void depthFirstTraverse(int nodeIndex);

	//广度优先遍历
	void breadthFirstTraverse(int nodeIndex);

private:
	//从矩阵中获取值
	bool getValueFromMatrix(int row, int col, int &val);
	//广度优先遍历
	void breadthFirstTraverseImpl(vector<int> preVec);

private:
	//图中最多可以容纳的顶点数
	int m_iCapacity;
	//已经添加的顶点个数
	int m_iNodeCount;
	//用顶点数组来表示顶点
	//用来存放顶点数组
	//用来读图进行遍历
	Node *m_pNodeArray;
	//图的存储方式是邻接矩阵：边+顶点和边的关系
	//用来存放邻接矩阵
	//用来存储图
	int *m_pMatrix;

};

