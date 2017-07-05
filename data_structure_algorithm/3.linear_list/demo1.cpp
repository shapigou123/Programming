#include "List.h"
#include <iostream>
using namespace std;

int main(void)
{
	//调用构造函数
	//3 5 7 2 9 1 8
	//采用构造函数的方式进行赋值
	Coordinate e1(3,5);
	Coordinate e2(5,7);
	Coordinate e3(6,8);
	//Coordinate e4 = 2;
	//Coordinate e5 = 9;
	//Coordinate e6 = 1;
	//Coordinate e7 = 1;
	//int e7 = 8;
	Coordinate temp(0,0);
	List *list1 = new List(10);
	
	//cout<<"length:"<<list1->ListLength()<<endl;
	
	list1->ListInsert(0,&e1);
	list1->ListInsert(1,&e2);
	list1->ListInsert(2,&e3);
	// list1->ListInsert(3,&e4);
	// list1->ListInsert(4,&e5);
	// list1->ListInsert(5,&e6);
	// list1->ListInsert(6,&e7);
	
	
	list1->GetElem(0,&temp);
	cout<<"temp:"<<temp<<endl;

	cout<<"local:"<<list1->LocateElem(&temp)<<endl;
	
	
	list1->PriorElem(&e3, &temp);
	cout<<"PirorElem:"<<temp<<endl;
	
	Coordinate temp1(0,0);
	list1->NextElem(&e3, &temp1);
	cout<<"NextElem:"<<temp1<<endl;
	
	//cout<<"length:"<<list1->ListLength()<<endl;
	//list1->ListDelete(0,&temp);
	
	// if(!list1->ListEmpty())
	// {
		// cout<<"not empty"<<endl;
	// }
	
	//list1->ClearList();
	//cout<<"length:"<<list1->ListLength()<<endl;
	
	// if(list1->ListEmpty())
	// {
		// cout<<"empty"<<endl;
	// }
	list1->ListTraverse();
	
	//cout<<"#"<<temp<<endl;
	//调用析构函数
	delete list1;
	list1 = NULL;
	return 0;
}