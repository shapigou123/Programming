#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node(char data = 0);
	//当前节点的存储的数据
	char m_cDate;
	//表示当前节点是否被访问过
	bool m_bIsVisited;
};



#endif