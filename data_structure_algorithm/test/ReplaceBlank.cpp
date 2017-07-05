#include <iostream>
//#include <string.h>
//#include <cstring>
using namespace std;


void ReplaceBlank(char string[], int length)
{
	if(string == NULL || length <= 0)
		return;
	
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		++originalLength;
		
		if(string[i] == ' ')
			++numberOfBlank;
		
		++i;
	}
	
	int newLength = originalLength + 2*numberOfBlank;
	
	cout<<originalLength<<endl;
	cout<<newLength<<endl;
	
	if(newLength>length)
		return;
	
	int IndexOfNew = newLength;
	int IndexOfOriginal = originalLength;
	while(IndexOfNew >= 0 && IndexOfOriginal<IndexOfNew)
	{
		if(string[IndexOfOriginal] == ' ')
		{
			string[IndexOfNew--] = '0';
			string[IndexOfNew--] = '2';
			string[IndexOfNew--] = '%';
		}
		else
		{
			string[IndexOfNew--] = string[IndexOfOriginal];	
		}
		
		--IndexOfOriginal;
	}
	
}


int main(void)
{
	
	char str[128] = "we are happy";
	//char str[128] = " ";
	cout<<str<<endl;
	ReplaceBlank(str,128);
	cout<<str<<endl;
	
	return 0;
	
}
















