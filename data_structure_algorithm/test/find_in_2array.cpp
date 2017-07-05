#include<iostream>
using namespace std;

#define NROWS	4
#define NCOLUMN	4
//bool Find(int a[][NCOLUMN], int *rows, int *colums, int key)
bool Find(const int (*a)[NCOLUMN], int *rows, int *colums, int key)
{
	bool flag = false;
	if(a != NULL && rows>0 && NCOLUMN>0)
	{
		int row = 0;
		int colum = NCOLUMN-1;
		while(row<NROWS && colum>=0)
		{
			//if(a[row*colums + colum] == key)
			if(a[row][colum] == key)
			{
			flag = true;
			*rows = row;
			*colums = colum;
			break;
			}
			//else if(a[row*colums + colum] > key)
			else if(a[row][colum] > key)
			{
				colum--;
			}
			else
				row++;
		}
	}
	return flag; 
}


int main(void)
{
	int a[NROWS][NCOLUMN]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	//int (*p)[] = a;
	int i,j;
	bool flag = Find(a,&i,&j,15);
	if(flag == true)
	{
		cout<<"find the key"<<endl;
		cout<<"("<<i<<","<<j<<")"<<endl;
	}
	else
		cout<<"can not find the key"<<endl;
	return 0;
	
}




