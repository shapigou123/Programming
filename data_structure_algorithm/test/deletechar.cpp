#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

char* changeA()	//代码区的常量字符串不允许修改
{
	char *p = "anc";
	return p;
}

int main(void)
{
	//char *s = changeA();
	//cout<<s<<endl;
	char str[] = "abcCAS";
	strlwr(str);
	cout<<str<<endl;
	return 0;
	
}



// char *p1 = "abc";	//p1 p2存储的是代码区的地址
// char *p2 = "abc";	//常量字符串，同时同一个字符串，故地址相同（p1 = p2）

// char str1[10] = "hello"; 	//str1 str2都是数组，存储的是内容
// char str2[10] = "hello";	//栈的方向是向上生长（高地址向低地址方向生长）str1 ！= str2

















