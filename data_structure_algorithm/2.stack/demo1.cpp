#include <iostream>
#include "Coordinate.h"
#include "stack.h"
#include <string.h>

using namespace std;
#define BINARY		2
#define	OCTONARY	8
#define	HEXADECIMAL	16

int main(void)
{
	//定义两个栈，一个用于保存扫描到的字符并且没有匹配上的情况，
	//另一个用于存放当前最急需的匹配符,与第一个栈的栈顶进行匹配
	MyStack<char> *pStack = new MyStack<char>(30);
	
	MyStack<char> *pNeedStack = new MyStack<char>(30);
	
	char str[] = "[()()[]]";
	
	//表示当前所需要的字符，必须为不可见字符的ASCLL码值
	char currentNeed = 0;
	
	for(int i = 0; i<strlen(str); i++)
	{
		if(str[i] != currentNeed)
		{
			pStack->push(str[i]);
			switch(str[i])
			{
				case'[':
					if(currentNeed != 0)
					{
						pNeedStack->push(currentNeed);
					}
					currentNeed = ']';
					break;
				
				case'(':
					if(currentNeed != 0)
					{
						pNeedStack->push(currentNeed);
					}
					currentNeed = ')';
					break;
				default:
					cout<<"字符串不匹配"<<endl;
					return 0;
			}
		}
		else
		{
			char elem;
			pStack->pop(elem);
			
			//pNeedStack->pop(currentNeed)后currentNeed就存放着此时栈顶所需要的匹配符
			//注意：当字符串前面部分有匹配完成的时候，pNeedStack就为空，
			//此时currentNeed就存放着最后一次所需要的匹配符
			if(!pNeedStack->pop(currentNeed))	//判断出栈是否正确
			{
				//当pNeedStack全部出栈后再进行出栈操作时，在pop会给currentNeed赋初值0
				currentNeed = 0;		
			}
		}
		
	}
	
	if(pStack->StackEmpty())
	{
		cout<<"字符串匹配"<<endl;
	}
	else
	{
		cout<<"字符串不匹配"<<endl;
	}
	
	delete pStack;
	pStack = NULL;
	delete pNeedStack;
	pStack = NULL;
	return 0;
}