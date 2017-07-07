#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>



#define _CRT_SECURE_NO_WARINGS

using namespace std;

void DeleteChar(char *str, char ch)
{
	if (str == NULL)
		return;

	int i = 0;
	int j = 0;
	while (str[i] != '\0') //字符中\0的编号等于0
	{
		str[i] = str[j];	//同步的自己赋值自己没影响，异步就覆盖
		if (str[i] != ch)
		{
			i++;
		}
		j++;
	}

}


void delcharbyaddr(char *str, char ch)
{
	//找到字符串中第一个ch字符，并将地址返回
	char *p = strchr(str, ch);
	if (p == NULL)
	{
		return;
	}
	else
	{
		char *p1 = p;
		char *p2 = p + 1;
		//方法一
		while (*p1 != '\0')//不处理尾部的字符
		{
			*p1 = *p2;
			p1++;
			p2++;
		}
		*p1 = *p2;	//尾部的\0再次赋值

		//方法二
		while (*p1)//处理尾部的字符
		{
			*p1 = *p2;
			p1++;
			p2++;
		}
		//方法三
		while(*p1++ = *p2++)
		{
		}

	}
}

void delchar(char *str, char ch)
{
	
	//找到字符串中第一个ch字符，并将地址返回
	char *p = strchr(str, ch);
	if (p == NULL)
	{
		return;
	}
	else 
	{
		//此时把'\0'也拷贝过来了
		for (int i = 0; i < strlen(p); i++) //下标法
			p[i] = p[i + 1];

	}
}

void delstr(char *str, char *chx)
{
	char *p = strstr(str, chx);
	if (p == NULL)
	{
		return;
	}
	else 
	{
		int len = strlen(chx);	//移动的距离

		//常规
		//for (int i = 0; i <= strlen(p) - len; i++)
		//{
		//	p[i] = p[i + len];
		//}

		//指针法
		while (*p = *(p + len))
			p++;
	}
}


void delallstr(char *str, char *chx)
{
	int i = 0;
	int j = 0;

	//先赋值，后比较
	while ((str[i] = str[j]) != '\0')
	{
		int flag = 1;	//假设找到
		for (int k = 0; k < strlen(chx); k++)
		{
			//查找，有一个不等就不等，预防母串提前结束
			if (str[j + k]!=chx[k] || str[j + k]=='\0')
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)	//！flag
		{
			i++;
			j++;	//找到不则同步
		}
		else
		{
			j += strlen(chx);//找到，同步的步骤
		}
	}
}


void delallstraddr(char *str, char *chx)
{
	char *p1 = str;
	char *p2 = str;
	//先赋值，后比较
	while ((*p1 = *p2) != '\0')
	{
		int flag = 1;	//假设找到
		char *px = p2;
		char *py = chx;
		while(*py != '\0')
		{
			if (*px != *py || *py == '\0')
			{
				flag = 0;
				break;
			}
			px++;
			py++;

		}
		if (flag == 0)	//！flag
		{
			p1++;
			p2++;	//找到不则同步
		}
		else
		{
			p2 += strlen(chx);//找到，同步的步骤
		}	
	}
}





void delwchar(wchar_t *str, wchar_t *wchar)
{
	wchar_t *p1 = str;
	wchar_t *p2 = str;
	while ((*p1 = *p2) != L'\0')
	{
		int flag = 1;
		wchar_t *px = p2;
		wchar_t *py = wchar;
		while(*py != L'\0')
		{
			if(*px != *py || *wchar == L'\0')
			{
				flag = 0;
				//break;
			}
			px++;
			py++;
		}
		if (flag == 0)
		{
			p1++;
			p2++;
		}
		else
		{
			p2 += wcslen(wchar);
		}
	}
}



int maind()
{
	setlocale(LC_ALL, "zh-CN");//设置中文状态
	wchar_t ch[] = L"我爱中国,中国爱我";
	//宽字符占两个字节，一个汉字长度就为1
	//wprintf(L"%ls\n", ch);
	//int len = wcslen(ch);
	//cout << len << endl;

	wchar_t wstr[10] = L"中国";
	delwchar(ch, wstr);
	wprintf(L"%ls\n",ch);

	char str[1024] = "i love china  love you  i love money  i love girl";
	
	delallstraddr(str, "love");
	cout << str <<endl;
	system("pause");
	return 0;
}