#include <stdio.h>

void quickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int tmp; //基准值

	if(left<right)
	{
		tmp = arr[left]; //记录基准值
		while(i != j)
		{
			while(i<j && arr[j]>tmp)
				j--;
			arr[i] = arr[j];
			while(i<j && arr[i]<tmp)
				i++;
			arr[j] = arr[i];
		}
		arr[i] = tmp;
		quickSort(arr,left,i-1);
		quickSort(arr,i+1,right);

	}
}

int main()
{
	int i;
	int arr[] = {2,3,47,1,6,0,-1,22,78,12};
	quickSort(arr, 0, 9);
	for(i=0; i<10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
