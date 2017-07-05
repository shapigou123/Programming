#include <iostream>

using namespace std;

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sorting(int array[], int array_len)
{
	int i,j;
	for(i=0; i<array_len-1; i++)
	{
		for(j=i+1; j<array_len; j++)
		{
			if(array[i]>array[j])	//a[i]中记录的是一趟排序下来最小的元素
			{
				Swap(&array[i], &array[j]);
			}
		}
	}
				
}

void bubble_2_sorting(int array[], int array_len)
{
	int left = 1;
	int right = array_len - 1;
	int flag = -1;
	int i;
	while(left<=right)
	{
		for(i=right; i>=left; i--)	//比较方向：从右到左，找出最小的元素，放在序列首位
		{
			if(array[i]<array[i-1])	
			{
				Swap(&array[i],&array[i-1]);
				flag = i;			//i用来记录已经排好序的元素
			}	
		}
		left = flag+1;				//下次排序的范围就除去了已排好的元素
		
		for(i=left; i<right+1; i++)
		{
			if(array[i]<array[i-1])
			{
				Swap(&array[i],&array[i-1]);
				flag = i;
			}	
		}
		right = flag-1;	
	}	
}


void quick_sorting(int array[], int low,int high)
{
	int i,j,index;
	if(low>=high)
		return;
	i=low;
	j=high;
	index = array[i];
	while(i<j)					//左边为小于index；右边为大于index
	{
		while(i<j && array[j] >= index)
			j--;		//找到a[j]<index 的值，若a[j]>=index,则继续向左移动
		if(i<j)
			array[i] = array[j];	//a[j]<index 时，交换a[i] a[j],i同时向右移动
		
		while(i<j && array[i] < index)
			i++;
		if(i<j)
			array[j] = array[i];
	}	
		array[i] = index;		//将首位元素移动到分割处
		quick_sorting(array,low,i-1);
		quick_sorting(array,i+1,high);
	
}



int main(void)
{	
	int len, ret, i;
	int array[] = {2,4,5,3,2,47,9,11,7,8};
	len = (sizeof(array)/sizeof(int));
	//shell_sort_ascending(array, len);
	quick_sorting(array, 0, len-1);
	for(i = 0; i<len; i++)
	{
		cout<<array[i]<<' ';
	}
	cout<<endl;
	//ret = binsearch(array, 10, 8);
//	printf("ret = %d\n",ret);
	
	return 0;
}
