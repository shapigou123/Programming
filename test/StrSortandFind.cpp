#include <iostream>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARINGS
using namespace std;


void teststrcmp()
{
	cout << strcmp("calc", "calc") << endl;	//���0
	cout << strcmp("aalc", "calc") << endl; //С��-1
	cout << strcmp("calc", "aalc") << endl; //����1
}


//����û�и�������
//���ݲ�������������
void sort(char *cmd[10])
{
	for (int i = 0; i < 10 - 1; i++)
	{
		//ÿ����һ�֣���С�ķ�����ǰ��
		for (int j = i+1; j < 10; j++)
		{
			if(strcmp(cmd[i], cmd[j])>0)
			{
				//cmd[i]Ϊÿ�ֱȽ�����С�ģ�ÿ�ֱȽ��л�䣩
				swap(cmd[i], cmd[j]);
			}

		}
		
	}
}

//��ӡ
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