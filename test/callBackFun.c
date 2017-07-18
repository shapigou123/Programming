#include <stdio.h>

//为回调函数声明类型定义
typedef int (*callBackFun)(char *);

//方法1，格式符合callBackFun的格式，可以看出是一个callBackFun
int fun1(char *p)
{
	printf("fun1：%s\n",p);
	return 0;
}

int fun2(char *p)
{
	printf("fun2：%s\n",p);
	return 0;
}


//执行回调函数，方法一，通过命名的方式
int call1(char *p, callBackFun pCallBack)
{
	printf("call1:%s\n",p);
	pCallBack(p);
	return 0;
}

// 执行回调函数，方式二：直接通过方法指针
// 或者是int call2(char *p, int (*ptr)(char *)) 同时ptr可以任意取
int call2(char *p, int (*pCallBack)(char *p))
{
	printf("call2:%s\n",p);
	(*pCallBack)(p);
	return 0;
}

int main()
{  
    char *p = "hello";
    call1(p, fun1);  
    call1(p, fun2);
    call2(p, fun1);  
    call2(p, fun2);
    return 0;
}