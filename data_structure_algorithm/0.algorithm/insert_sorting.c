#include<stdio.h>

/*****************插入排序之直接插入排序*****************/
void insert_sort_ascending(int *data, int num)
{
	int i,j;
	int tmp;
	for(i = 1; i < num; i++)
	{
		tmp = data[i];
		j = i-1;
		while((j >= 0)&&(tmp < data[j]))
		{
			data[j+1] = data[j];
			j--;
		}	
		data[j+1]=tmp;
	}
}

int insert_sort_descending(int *data, int num)
{
	int i,j;
	int tmp;
	for(i = 1; i < num; i++)
	{
		tmp = data[i];
		for(j = i-1; j >= 0; j--)
		{
			if(tmp > data[j])
			{
				data[j+1] = data[j];
			}
			else	//降序排列，小与直接退出循环，i++
				break;
				
		}
		data[j+1]=tmp;
	}
	
}
/****************************************************/



/*****************插入排序之希尔排序*****************/

void shell_sort_ascending(int array[], int array_len)
{
	int i,k,gap,tmp;
	for(gap = array_len/2; gap > 0; gap = gap/2 )	//步长
	{	
		for(i = gap;i < array_len; i++)				//直接插入排序
		{
			tmp = array[i];
			k = i - gap;
			while((k >= 0) && (tmp < array[k]))
			{
				array[k + gap] = array[k];
				k -= gap;
			}
			array[k+gap] = tmp;		
		}	
	}
}

void shell_sort_descending(int array[], int array_len)
{
	int i,k,gap,tmp;
	for(gap = array_len/2; gap > 0; gap = gap/2 )	//步长
	{	
		for(i = gap;i < array_len; i++)				//直接插入排序
			for(k = i-gap; k >= 0 && array[k] < array[k+gap]; k-=gap)
			{	
				tmp = array[k+gap];
				array[k+gap] = array[k];
				array[k] = tmp;
			}	
	}
}

void shell_sort(int array[], int array_len)
{
	int i,j,gap,tmp;
	gap = array_len/2;
	while(gap>0)
	{
		for(i = gap; i<array_len; i++)
		{
			tmp = array[i];
			j = i-gap;
			while(j>=0 && tmp<array[j])
			{
				array[j+gap] = array[j];
				j = j-gap;
			}
			array[j+gap] = tmp;	
			//j = j-gap;
		}
		gap = gap/2;
	}
	
}

/****************************************************/



/*****************插入排序之二分查找*****************/
//前提数组是递增的
int binsearch(int array[], int array_len, int data)
{
	int low = 0;
	int high = array_len - 1;
	while(low <= high)
	{
		int middle = (low + high)/2;
		if(data < array[middle])
			high = middle - 1;
		else if(data > array[middle])
			low = middle + 1;
		else
			return middle;
	}
	return -1;
	
}


void binary_insert_sort(int array[], int array_len)
{
	int i,j,low,high;
	int tmp,middle;
	
	for(i = 1; i < array_len; i++)	//开始第一个元素被当做已经排好的部分
	{
		low = 0;
		high = i - 1;
		tmp = array[i];
		while(low <= high)
		{
			middle = (low + high)/2;
			if(tmp < array[middle])		//即将插入的元素放在左区间
				high = middle - 1;
			else
				low = middle + 1;		//即将插入的元素放在右区间
		}
		//每次查找完毕后，low总比high大一，array[low]总是存放第一个比tmp大的数，因此应从此处开始，每       //个元素右移一位，并将tmp存入array[low]中，这样就保证了array[0...i]是排好序的
		for(j = i-1; j >= low; j--)
			array[j+1] = array[j];
		array[low] = tmp;
	}
	
}





/****************************************************/





int main(void)
{	
	int len, ret, i;
	int array[] = {2,4,5,3,123,2,47,9,11,7,8,99,1,0,38,999,7};
	len = (sizeof(array)/sizeof(int));
	//shell_sort_ascending(array, len);
	insert_sort_descending(array, len);
	for(i = 0; i<len; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	//ret = binsearch(array, 10, 8);
//	printf("ret = %d\n",ret);
	
	return 0;
}

