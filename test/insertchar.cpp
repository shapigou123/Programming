#include <iostream>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARINGS
using namespace std;


void insertstr(char *str, char *insertStr, char *strpos)
{
	//���ҵ�����posָ��hello�ĵ�һ���ַ���h��
	char *pos = strstr(str, strpos);
	if (pos != NULL)
	{
		pos += strlen(strpos)+1;	//Ҫ�����λ�ã�����ԭ����w����λ�ÿ�ʼ����
		int len = strlen(insertStr);
		//ѭ������β����\0����ʼ��ǰ��		
		for (char *p = str + strlen(str); p >= pos; p--)
		{
			//Ҫ���뼸���ַ����������ƶ�����
			*(p + len) = *p;
		}

		for (char *p = insertStr, *pnew = pos; *p != '\0'; p++, pnew++)
		{
			*pnew = *p;
		}
	}
}

int maini(void)
{
	char str[100] = "VS2015��hello world my name is yuyang";
	char insertStr[10] = "C++";
	insertstr(str, insertStr, "hello");

	/*strcat(str, insertStr);*/
	cout << str << endl;
	system("pause");
	return 0;

}