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
	while (str[i] != '\0') //�ַ���\0�ı�ŵ���0
	{
		str[i] = str[j];	//ͬ�����Լ���ֵ�Լ�ûӰ�죬�첽�͸���
		if (str[i] != ch)
		{
			i++;
		}
		j++;
	}

}


void delcharbyaddr(char *str, char ch)
{
	//�ҵ��ַ����е�һ��ch�ַ���������ַ����
	char *p = strchr(str, ch);
	if (p == NULL)
	{
		return;
	}
	else
	{
		char *p1 = p;
		char *p2 = p + 1;
		//����һ
		while (*p1 != '\0')//������β�����ַ�
		{
			*p1 = *p2;
			p1++;
			p2++;
		}
		*p1 = *p2;	//β����\0�ٴθ�ֵ

		//������
		while (*p1)//����β�����ַ�
		{
			*p1 = *p2;
			p1++;
			p2++;
		}
		//������
		while(*p1++ = *p2++)
		{
		}

	}
}

void delchar(char *str, char ch)
{
	
	//�ҵ��ַ����е�һ��ch�ַ���������ַ����
	char *p = strchr(str, ch);
	if (p == NULL)
	{
		return;
	}
	else 
	{
		//��ʱ��'\0'Ҳ����������
		for (int i = 0; i < strlen(p); i++) //�±귨
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
		int len = strlen(chx);	//�ƶ��ľ���

		//����
		//for (int i = 0; i <= strlen(p) - len; i++)
		//{
		//	p[i] = p[i + len];
		//}

		//ָ�뷨
		while (*p = *(p + len))
			p++;
	}
}


void delallstr(char *str, char *chx)
{
	int i = 0;
	int j = 0;

	//�ȸ�ֵ����Ƚ�
	while ((str[i] = str[j]) != '\0')
	{
		int flag = 1;	//�����ҵ�
		for (int k = 0; k < strlen(chx); k++)
		{
			//���ң���һ�����ȾͲ��ȣ�Ԥ��ĸ����ǰ����
			if (str[j + k]!=chx[k] || str[j + k]=='\0')
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)	//��flag
		{
			i++;
			j++;	//�ҵ�����ͬ��
		}
		else
		{
			j += strlen(chx);//�ҵ���ͬ���Ĳ���
		}
	}
}


void delallstraddr(char *str, char *chx)
{
	char *p1 = str;
	char *p2 = str;
	//�ȸ�ֵ����Ƚ�
	while ((*p1 = *p2) != '\0')
	{
		int flag = 1;	//�����ҵ�
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
		if (flag == 0)	//��flag
		{
			p1++;
			p2++;	//�ҵ�����ͬ��
		}
		else
		{
			p2 += strlen(chx);//�ҵ���ͬ���Ĳ���
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
	setlocale(LC_ALL, "zh-CN");//��������״̬
	wchar_t ch[] = L"�Ұ��й�,�й�����";
	//���ַ�ռ�����ֽڣ�һ�����ֳ��Ⱦ�Ϊ1
	//wprintf(L"%ls\n", ch);
	//int len = wcslen(ch);
	//cout << len << endl;

	wchar_t wstr[10] = L"�й�";
	delwchar(ch, wstr);
	wprintf(L"%ls\n",ch);

	char str[1024] = "i love china  love you  i love money  i love girl";
	
	delallstraddr(str, "love");
	cout << str <<endl;
	system("pause");
	return 0;
}