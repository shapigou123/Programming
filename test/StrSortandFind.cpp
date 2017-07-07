#include <iostream>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARINGS
using namespace std;


void teststrcmp()
{
	cout << strcmp("calc", "calc") << endl;	//相等0
	cout << strcmp("aalc", "calc") << endl; //小与-1
	cout << strcmp("calc", "aalc") << endl; //大于1
}


//数组没有副本机制
//传递参数，进行排序
void sort(char *cmd[10])
{
	for (int i = 0; i < 10 - 1; i++)
	{
		//每经过一轮，最小的放在最前面
		for (int j = i+1; j < 10; j++)
		{
			if(strcmp(cmd[i], cmd[j])>0)
			{
				//cmd[i]为每轮比较中最小的（每轮比较中会变）
				swap(cmd[i], cmd[j]);
			}

		}
		
	}
}

//打印
void showstr(char *cmd[10])
{
	for (int i = 0; i < 10; i++)
		cout << cmd[i] << " ";
	cout << endl;
}


int mains(void)
{
	char *cmd[10] = { "calc","123456","abcd","ak47","AMP","M16","notepad","tasklist","run","mspaint" };
	showstr(cmd);
	sort(cmd);
	showstr(cmd);
	system("pause");
	return 0;
}