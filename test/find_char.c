#include <stdio.h>


int find_char(char **strings, char value)
{
	char *string = NULL;	//当前正在查找的字符串

	while((string = *strings++) != NULL)
	{
		while(*string != '\0')
		{
			if(*string++ == value)
				return 0;
		}

	}
	return -1;
}

int main()
{
	int ret = -1;
	char *strings[]={"hello","c","sudu",NULL};
	ret = find_char(strings,'w');
	if(ret == 0)
		printf("find!\n");
	else
		printf("not find!\n");

	return 0;
}
