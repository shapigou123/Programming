#include <iostream>

using namespace std;



int main(void)
{	
	int len, ret, i;
	int array[] = {2,4,5,3,2,47,9,11,7,8};
	len = (sizeof(array)/sizeof(int));
	//shell_sort_ascending(array, len);
	MergeSorting(array, 0, len-1);
	for(i = 0; i<len; i++)
	{
		cout<<array[i]<<' ';
	}
	cout<<endl;	
	return 0;
}
