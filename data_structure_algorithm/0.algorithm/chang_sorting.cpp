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
			if(array[i]>array[j])	//a[i]�м�¼����һ������������С��Ԫ��
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
		for(i=right; i>=left; i--)	//�ȽϷ��򣺴��ҵ����ҳ���С��Ԫ�أ�����������λ
		{
			if(array[i]<array[i-1])	
			{
				Swap(&array[i],&array[i-1]);
				flag = i;			//i������¼�Ѿ��ź����Ԫ��
			}	
		}
		left = flag+1;				//�´�����ķ�Χ�ͳ�ȥ�����źõ�Ԫ��
		
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
	while(i<j)					//���ΪС��index���ұ�Ϊ����index
	{
		while(i<j && array[j] >= index)
			j--;		//�ҵ�a[j]<index ��ֵ����a[j]>=index,����������ƶ�
		if(i<j)
			array[i] = array[j];	//a[j]<index ʱ������a[i] a[j],iͬʱ�����ƶ�
		
		while(i<j && array[i] < index)
			i++;
		if(i<j)
			array[j] = array[i];
	}	
		array[i] = index;		//����λԪ���ƶ����ָ
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
