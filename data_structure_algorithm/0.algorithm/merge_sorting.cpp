#include <iostream>

using namespace std;

//�������array[p...q]��array[q+1,...r]�鲢Ϊ�����array[p...r]
void Merge(int array[], int p, int q,int r)		
{
	int i,j,k,n1,n2;
	n1 = q-p+1;
	n2 = r-q;
	int *L = new int[n1];
	int *R = new int[n2];
	for(i=0,k=p;i<n1;i++,k++)		//��ԭarray�����۷ֳ�L��R���飬LΪ��ߵģ�RΪ�ұߵ�
		L[i] = array[k];
	
	for(j=0,k=q+1;j<n2;j++,k++)
		R[j] = array[k];
	
	for(i=0,j=0,k=p;i<n1 & j<n2; k++)	//���������������У���ķ�������λ
	{
		if(L[i]>R[j])
		{
			array[k]=L[i];
			i++;
		}
		else
		{
			array[k]=R[j];
			j++;
		}	
	}
	while(i<n1)				//���Ƶ�һ��������ʣ�µ�Ԫ��
	{
		array[k++] = L[i++];
	}
	while(j<n2)				//���Ƶڶ���������ʣ�µ�Ԫ��
	{
		array[k++] = R[j++];
	}
	
}

void Merge1(int a[], int low, int mid, int high)
{
	int i=low;
	int j = mid+1;
	int k = 0;
	int *r = new int[high-low+1];
	
	while(i<=mid && j<=high)
	{
		if(a[i]>a[j])
		{
			r[k]=a[i];
			i++;
			k++;
		}
		else
		{
			r[k]=a[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid)
	{
		r[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		r[k]=a[j];
		j++;
		k++;
	}
	
	for(k=0,i=low; i<=high; k++,i++)
	{
		a[i] = r[k];
	}	
}


void MergeSorting(int array[],int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		MergeSorting(array, low, mid);		//���
		MergeSorting(array, mid+1, high);	//�ұ�
		Merge(array, low, mid, high);
	}
	
}

int main(void)
{	
	int len, ret, i;
	int array[] = {2,4,5,3,2,47,9,11,7,8,100};
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















