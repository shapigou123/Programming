#include "single_list.h"
#include "Node.h"
#include "Person.h"
#include <iostream>
using namespace std;
/**
	线性表——通讯录
	联系人信息：姓名 电话

**/


int menu()
{
	//显示通讯录功能菜单
	cout<< "功能菜单"<<endl;
	cout<< "1.新建联系人"<<endl;
	cout<< "2.删除联系人"<<endl;
	cout<< "3.浏览联系人"<<endl;
	cout<< "4.退出通讯录"<<endl;
	
	cout<<"请输入：";
	
	int order = 0;
	cin>>order;
	return order;
}

void createPerson(List *pList)
{
	Node node;
	
	Person person;
	cout<<"请输入姓名：";
	cin >> person.name;
	cout<<"请输入电话：";
	cin >> person.phone;
	node.data = person;
	
	//注意这里的node是栈内存，函数结束时会回收内存
	//故插入的时候，应该在这个插入函数中将node的data取出并赋值给newNode，
	//而不要将当前形参的pNode给挂载到链表上,否则函数执行完，内存回收，就会出现内存的访问错误
	pList->ListInsertTail(&node);
}

bool removePerson(List *pList)
{
	Node node;
	//Person person;
	int i = -1;
	
	cout<<"请输入要删除联系人的姓名：";
	cin>>node.data.name;
	cout<<"请输入要删除联系人的电话：";
	cin>>node.data.phone;
	
	i = pList->LocateElem(&node);
	
	//int LocateElem(Node *e);
	if(i == -1)
	{
		return false;
	}
	pList->ListDelete(i, &node);
	return true;
	
}

int main(void)
{	
	int UserOrder = 0;
	List *pList = new List();	//调用List的构造函数
	while(UserOrder != 4)
	{
		UserOrder = menu();
		switch(UserOrder)
		{
		case 1:
			cout<<"用户指令--->>新建联系人"<<endl;
			createPerson(pList);
			break;
		case 2:
			cout<<"用户指令--->>删除联系人"<<endl;
			removePerson(pList);
			break;
		case 3:
			cout<<"用户指令--->>浏览联系人"<<endl;
			pList->ListTraverse();
			break;
		case 4:
			cout<<"用户指令--->>退出通讯录"<<endl;
			break;
		}
		
	}
	
	// Node node1;
	// Node node2;

	
	// node1.data.name ="yuyang";
	// node1.data.phone ="123456";
	// node2.data.name ="hello";
	// node2.data.phone ="654321";

	// Node temp;
	// temp.data = -1;

	
	// pList->ListInsertHead(&node1);
	// pList->ListInsertHead(&node2);
	// pList->ListInsertHead(&node3);
	// pList->ListInsertHead(&node4);
	 // pList->ListInsertTail(&node1);
	 // pList->ListInsertTail(&node2);

	
	// pList->ListInsert(0,&node5);
	
	//pList->ListDelete(4,&temp);
	//pList->GetElem(4,&temp);
	
	// pList->PriorElem(&node3,&temp);
	// cout<<"PriorElem:"<<temp.data<<endl;
	
	// pList->NextElem(&node3,&temp);
	// cout<<"NextElem:"<<temp.data<<endl;
	
	//cout<<"locate:"<<pList->LocateElem(&node3)<<endl;
	
	// cout<<"length:"<<pList->ListLength()<<endl;
	
	// pList->ListTraverse();
	
	
	delete pList;
	pList = NULL;
	
	return 0;
}