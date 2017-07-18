#include <cstdio>  
int i;    //记录步数  
//i表示进行到的步数,将编号为n的盘子由from柱移动到to柱(目标柱)  
void move(int n,char from,char to){  
    printf("第%d步:将%d号盘子%c---->%c\n",i++,n,from,to);  
}  
  
//汉诺塔递归函数  
//n表示要将多少个"圆盘"从起始柱子移动至目标柱子  
//start_pos表示起始柱子,tran_pos表示过渡柱子,end_pos表示目标柱子  
void Hanio(int n,char start_pos,char tran_pos,char end_pos){  
    if(n==1){    //很明显,当n==1的时候,我们只需要直接将圆盘从起始柱子移至目标柱子即可.  
        move(n,start_pos,end_pos);  
    }  
    else{  
        Hanio(n-1,start_pos,end_pos,tran_pos);   //递归处理,一开始的时候,先将n-1个盘子移至过渡柱上  
        move(n,start_pos,end_pos);                //然后再将底下的大盘子直接移至目标柱子即可  
        Hanio(n-1,tran_pos,start_pos,end_pos);    
        //然后重复以上步骤,递归处理放在过渡柱上的n-1个盘子   
    }  
}  
int main(){  
    int n;  
    while(scanf("%d",&n)==1&&n){  
        i = 1;   //全局变量赋初始值  
        Hanio(n,'1','2','3');  
        printf("最后总的步数为%d\n",i-1);  
    }  
    return 0;  
}  