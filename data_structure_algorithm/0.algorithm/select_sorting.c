#include<stdio.h>

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*****************选择排序之直接选择排序*****************/
void select_sort(int array[], int array_len)
{
	int i,j;
	int tmp,flag;
	for(i = 0; i < array_len-1; i++)
	{
		tmp = array[i];
		flag = i;
		for(j = i+1; j < array_len; j++)
		{
			if(array[j]<tmp)
			{
				flag = j;	//记录最下值的小标
				tmp = array[j];	//记录最小值
			}
		}	
		//把最下的元素放在数组首位
		if(flag != i)
		{
			array[flag] = array[i];
			array[i] = tmp;
		}
		
	}
}
/****************************************************/



/*****************选择排序之堆排序*****************/
//堆的插入
//新加入i结点  其父结点为(i - 1) / 2  
void MinHeapFixup(int a[], int i)
{
	int ParentNode,tmp;
	tmp = a[i];
	ParentNode = (i-1)/2;				//父结点 
	while((ParentNode >= 0)&&(i != 0))    
	{
		if(a[ParentNode] <= tmp)
			break;
		a[i] = a[ParentNode];			//把较大的子结点往下移动,替换它的子结点  
		i = ParentNode;
		ParentNode = (i-1)/2;
	}
	a[i] = tmp;		//较大的节点位于子节点

}

//插入时，在小根堆中加入新的数据Num
void MinHeapAddNumber(int a[], int n,int Num)
{
a[n] = Num;
MinHeapFixup(a, n);
}


//堆的删除
//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2  
void MinHeapFixdown(int a[], int i, int n)
{
	int LeftChildNode,tmp;
	LeftChildNode = i*2 + 1;
	tmp = a[i];
	while(LeftChildNode < n)
	{
		if(LeftChildNode+1<n && a[LeftChildNode+1]<a[LeftChildNode])	//左右孩子节点中找最小的
			LeftChildNode++;	//j为最小节点坐标
		if(a[LeftChildNode] >= tmp)
			break;
		a[i] = a[LeftChildNode];	 //把较小的子结点往上移动,替换它的父结点 
		i = LeftChildNode;
		LeftChildNode = (i+1)/2;
	}
	a[i] = tmp;		//较大的节点位于子节点
	
}


////在最小堆中删除数  
void MinHeapDeleteNumber(int a[], int n)  
{  
   // Swap(a[0], a[n-1]);  
    MinHeapFixdown(a, 0, n - 1);  
}  


//a为待调整的堆数组，i是待调整的数组元素的位置，length为数组长度；功能：根据数组建立大根堆
void HeapAdjust(int a[], int i, int length)
{
	int ChildNode, tmp;
	for(; 2*i+1<length; i=ChildNode)
	{
		ChildNode = 2*i+1;		
		if(ChildNode<length-1 && a[ChildNode+1]>a[ChildNode])
			++ChildNode;			//得到子节点中较大的节点
		
		if(a[i]<a[ChildNode])		//若较大的子节点大于父节点，则吧较大的子节点往上移动，替换它的父节点
			//Swap(a[i],a[ChildNode]);
		{
			tmp = a[i];
			a[i] = a[ChildNode];
			a[ChildNode] = tmp;
		}
		else	
			break;
	}
}

//调整序列的前半部分，调整完后第一个元素是序列的最大元素
void HeapSort(int a[], int length)
{
	int i;
	for(i=length/2-1; i>=0; --i)	//length/2-1是最后一个非叶子节点
	HeapAdjust(a, i, length);		//从最后一个元素开始对序列进行调整，不断的缩小调整范围知道第一个元素
		for(i=length-1; i>0; --i)
		{
			a[i] = a[0]^a[i];		//交换第一个元素和最后一个元素
			a[0] = a[0]^a[i];		//保证当前最后一个元素都是在这个序列中
			a[i] = a[0]^a[i];
			HeapAdjust(a, 0, i);	//不断的缩小heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
		}
	
}




void sift(int a[], int i, int len)
{
	int child = 2*i+1;
	while(child < len)
	{
		
	}
	
}















/**************************************************/


int main(void)
{	
	int len, ret, i;
	int array[] = {2,4,5,3,2,47,9,11,7,8};
	len = (sizeof(array)/sizeof(int));
	HeapSort(array, len);
	for(i = 0; i<len; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}

