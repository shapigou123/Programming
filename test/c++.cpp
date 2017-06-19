#include <iostream>

using namespace std;

char *fun()
{
	char str[] = "hello";
	return str; 
}
int main()
{
	char *p = fun();
	cout << *p << endl;
	return 0;
}

返回一个依赖参数的可写指针：
msg_hdr* get_hdr(char* buf)
{
    return (msg_hdr*)buf;
}
void get_hdr(char* buf, msg_hdr** hdr)
{
    *hdr = (msg_hdr*)buf;
}