#include <iostream>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARINGS
using namespace std;


void insertstr(char *str, char *insertStr, char *strpos)
{
	//若找到，则pos指向hello的第一个字符“h”
	char *pos = strstr(str, strpos);
	if (pos != NULL)
	{
		pos += strlen(strpos)+1;	//要插入的位置，即在原来“w”的位置开始插入
		int len = strlen(insertStr);
		//循环，从尾部‘\0’开始往前走		
		for (char *p = str + strlen(str); p >= pos; p--)
		{
			//要插入几个字符，就往后移动几个
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
	char str[100] = "VS2015，hello world my name is yuyang";
	char insertStr[10] = "C++";
	insertstr(str, insertStr, "hello");

	/*strcat(str, insertStr);*/
	cout << str << endl;
	system("pause");
	return 0;

}