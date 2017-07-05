#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void DeleteChar(char *str)
{
	if(str == NULL)
		return;
	
	int i = 0;
	int j = 0;
	while(str[i] != '\0')
	{
		str[i] = str[j];
		if(str[i] != '*')
		{
			i++;
		}
		j++;
	}
	
}
#endif

#if 0
void DeleteChar(char *str)
{
	if(str == NULL)
		return;
	
	int i = 0;
	int j = 0;
	while((str[i] = str[j++]) != '\0')
	{
		if(str[i] != '*')
		{
			i++;
		}
	}
	
}

#endif


void DeleteChar(char *str)
{
	if(str == NULL)
		return;
	
	char *p1 = str;
	char *p2 = str;
	
	while((*p1 = *(p2++)) != '\0')
	{
		if(*p1 != '*')
		{
			p1++;
		}
	}
	
}


int main1(void)
{
	char str[255] = {0};
	scanf("%[^\n]",str);
	DeleteChar(str);
	printf("%s\n",str);
	return 0;
	
}

int main(void)
{
	//char *s = changeA();
	//cout<<s<<endl;
	char str[] = "abcCAS";
	strupr(str);
	printf("%s\n",str);
	return 0;
	
}