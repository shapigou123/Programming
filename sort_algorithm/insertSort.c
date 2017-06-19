#include <stdio.h>

void directInsert(int arr[], int num)
{
	int tmp;
	int i, j;

	for(i=1; i<num; i++)
	{
		tmp = arr[i]; //tmp代表无序区元素
		j = i-1; //j表示有序区
		while(j>=0 && tmp < arr[j])
		{
			arr[j+1] = arr[j];	//元素后移，前面的元素赋值给后面的元素
			j--;
		}
		arr[j+1] = tmp;
	}
}

void binaryInsert(int arr[], int num)
{
	int tmp;
	int i,j;
	int high,low,mid;
	for(i=1; i<num; i++)
	{
		tmp =arr[i];
		low = 0;
		high = i-1;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(tmp<arr[mid])
				high--;
			else
				low++;
		}

		for(j=i-1; j>=high+1; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[high+1] = tmp;
	}
}

void shellInsert(int arr[], int num)
{
	int i,j,gap,tmp;
	gap = num/2;
	while(gap)
	{
		for(i=gap; i<num; i++)
		{
			tmp = arr[i];
			j = i-gap;
			while(j>=0 && tmp<arr[j])
			{
				arr[j+gap] = arr[j];
				j-=gap;
			}
			arr[j+gap] = tmp;
		}
		gap/=2;
	}



}
int main()
{
	int i;
	int arr[] = {2,3,47,1,6,99,-1,22,78,12};
	shellInsert(arr, 10);
	for(i=0; i<10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
