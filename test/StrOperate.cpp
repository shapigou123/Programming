#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;
/*�ַ�������*/

void diyStrCpy(const char *source, char *target, int len)
{
	int i = 0;
	while (source[i] != '\0')
	{
		i++;
	}
	//����д��if (i <= len)
	if (i < len)
	{
		i = 0;
		while (source[i] != '\0')
		{	
			target[i] = source[i];
			i++;
		}
		target[i] = '\0';
	
	}
	else
		return;
}

/*�ַ�������*/
void diyStrCat(char *str1, const char *str2)
{
	int i = 0;
	int k = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[k] != '\0')
	{
		str1[i++] = str2[k++];
	}

	str1[i] = '\0';
}

void diyStrCat2(char *str1, const char *str2, int len)
{
	int i = 0, k = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[k] != '\0')
		k++;
	if (k + i >= len)
		return;

	k = 0;
	//��ʱstr1[i]ָ��յ�λ��
	while (str2[k] != '\0')
	{
		str1[i++] = str2[k++];
	}

	str1[i] = '\0';

}

void diyStrCat3(const char *str1, const char *str2, char *target)
{
	int i = 0;
	int k = 0;
	while (str1[i] != '\0')
	{
		target[i] = str1[i];
		i++;
	}

	while (str2[k] != '\0')
	{
		target[i] = str2[k];
		i++;
		k++;
	}

	target[i] = '\0';
}



/*************************************************************
* �ַ����Ƚ�
*/
//��������ִ�Сд�������Ƕ�ת���ɴ�/Сд
bool diyStrCmp(char *str1, char *str2)
{
	int k = 0;
	while (str1[k] != '\0')
	{
		if (str1[k] != str2[k])
		{
			return false;
		}
		k++;
	}

	if (str1[k] != str2[k])
	{
		return false;
	}

	return true;
}





/*************************************************************
* �ַ�����Сдת��-Сд->��д
* A: 65->1000001
* a: 97->1100001
* ��λ������95->101 1111
*/
void diyStr2UpperEx(const char *source, char *target)
{
	int k = 0;
	while (source[k] != '\0')
	{
		//target[k] = source[k] & 95;
		target[k] = source[k] & 0x5f;
		k++;
	}
	target[k] = '\0';
}

void diyStr2Upper(const char *source, char *targe, int len)
{
	int i = 0;
	while (source[i] != '\0')
	{
		i++;
	}
	if (i >= len)
		return;

	i = 0;
	while (source[i] != '\0')
	{
		if (source[i] >= 'a' && source[i] <= 'z')
		{
			targe[i] = source[i] - 32;
		}
		else
		{
			targe[i] = source[i];
		}
		i++;
	}
	targe[i] = '\0';
}



/*************************************************************
* �ַ�����Сдת��-��д->Сд
* A: 65->1000001
* a: 97->1100001
* ��λ������32->0100000
*/
void diyStr2LowerEx(const char *source, char *target)
{
	int k = 0;
	while (source[k] != '\0')
	{
		//target[k] = source[k] | 32;
		target[k] = source[k] | 0x20;
		k++;
	}
	target[k] = '\0';
}

void diyStr2Low(const char *source, char *targe, int len)
{
	int i = 0;
	while (source[i] != '\0')
	{
		i++;
	}
	if (i >= len)
		return;

	i = 0;
	while (source[i] != '\0')
	{
		if (source[i] >= 'A' && source[i] <= 'Z')
		{
			targe[i] = source[i] + 32;
		}
		else
		{
			targe[i] = source[i];
		}
		i++;
	}
	targe[i] = '\0';
}


/*************************************************************
�ַ����ָ�
*/
int diySeparateStr(const char *source, char separator, char target[][20])
{
	int i = 0;
	int j = 0;
	int k = 0;

	if (source == NULL)
		return -1;

	while (source[i] != '\0')
	{

		if (source[i] != separator)
		{	
			target[k][j++] = source[i++];
		}
		else 
		{
			target[k][j] = '\0';
			j = 0;
			i++;
			k++;
		}	
	}
	target[k][j] = '\0';
	return k + 1;
}




int main1(void)
{

	char str1[21] = "abcdE123fG";

	char str2[] = "abcdE123fG";
	char tar1[20] = { 0 };
	//char tar2[20] = { 0 };
	//int len = strlen(str1);
	//diyStrCpy(str1, tar1, 20);
	diyStrCat(str1, str2);
	printf("%s\n", str1);
//	diyStr2LowerEx(str1, tar1);
//	diyStr2UpperEx(str2, tar2);

	//if (diyStrCmp(str1, str2))
	//	printf("str1 == str2\n");
	//else
	//	printf("str1 != str2\n");


	//diyStr2Upper(str1, tar1,20);
	//
	//diyStr2Low(str2, tar2, 20);

	//printf("2Upper: %s--> %s\n", str1, tar1);

	//printf("2Low: %s-->%s\n", str2, tar2);

	//const char str3[] = "abcd,ssl,911,kfc";
	//char str3[] = "";
	//char tar[4][20] = { 0 };
	//char separator = ',';
	//int n = diySeparateStr(str3, separator, tar);

	/*for (int i = 0; i < 11; i++)
	{
		printf("%s\n", tar1[i]);
	}*/

	system("pause");
	return 0;
}