#ifndef NODE_H
#define NODE_H

//#include "Person.h"
class Node
{	
	//将数据域和指针域都定义为public的访问权限,也方便了他们的赋值
	//就不需要定义数据域指针域相关的操作函数了
	
	//输出运算符重载
	//也可以定义成struct类型，它默认访问权限就是public类型
	public:
		int	data;
		//Person data;
		Node *pNext;
		
		void printNode();
		
		
};



#endif