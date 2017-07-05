#include "single_list.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main(void)
{	
	//Node node1; 两种写法都可以
	Node node1;
	Node node2;
	Node node3;
	Node node4;
	Node node5;
	node1.data = 3;
	node2.data = 4;
	node3.data = 5;
	node4.data = 6;
	node5.data = 99;
	Node temp;
	temp.data = -1;
	List *pList = new List();	//调用List的构造函数
	
	// pList->ListInsertHead(&node1);
	// pList->ListInsertHead(&node2);
	// pList->ListInsertHead(&node3);
	// pList->ListInsertHead(&node4);
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);
	
	pList->ListInsert(0,&node5);
	
	//pList->ListDelete(4,&temp);
	//pList->GetElem(4,&temp);
	
	// pList->PriorElem(&node3,&temp);
	// cout<<"PriorElem:"<<temp.data<<endl;
	
	// pList->NextElem(&node3,&temp);
	// cout<<"NextElem:"<<temp.data<<endl;
	
	//cout<<"locate:"<<pList->LocateElem(&node3)<<endl;
	
	cout<<"length:"<<pList->ListLength()<<endl;
	
	pList->ListTraverse();
	
	
	delete pList;
	pList = NULL;
	
	return 0;
}