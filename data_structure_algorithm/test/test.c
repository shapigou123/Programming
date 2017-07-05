#include<stdio.h>

int max(int a[], int len)
{
	int i,max;
	max = a[0];
	for(i=1; i<len; i++)
	{
		if(max<a[i])
			max = a[i];
	}
	return max;
}

int main()
{
/*     int N,a[1001]={0},res=0,i,t;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&t);
        if(a[t]==0)
        {
            a[t]=t;
            res++;
        }
    }
    printf("%d\n",res);
    for(i=0;i<1001;i++)
    {
        if(a[i]!=0) printf("%d ",a[i]);
    }
    
    return 0;
*/	
	int len, ret, i;
	int array[] = {2,4,5,3,2,47,9,11,7,8,100,9999};
	len = (sizeof(array)/sizeof(int));
	//shell_sort_ascending(array, len);
	printf("%d\n",max(array, len));
	return 0;

}