#ifndef NODE_H
#define NODE_H

//#include "Person.h"
class Node
{	
	//���������ָ���򶼶���Ϊpublic�ķ���Ȩ��,Ҳ���������ǵĸ�ֵ
	//�Ͳ���Ҫ����������ָ������صĲ���������
	
	//������������
	//Ҳ���Զ����struct���ͣ���Ĭ�Ϸ���Ȩ�޾���public����
	public:
		int	data;
		//Person data;
		Node *pNext;
		
		void printNode();
		
		
};



#endif