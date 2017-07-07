#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stack>
#include <vector>
#include <set>
#include <map>

using namespace std;


//int mainh(void)
//{
//	int indexValueNum;
//	while (cin >> indexValueNum)
//	{
//		map<int, int> m;
//		while (indexValueNum--)
//		{
//			int index, value;
//			cin >> index >> value;
//			if (!m[index])
//			{
//				m[index] = value;
//			}
//			else
//				m[index] += value;	//不存在时赋值，存在时累加
//		}
//		//map内部本身就是按照index大小顺序进行存储的
//		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
//			cout << it->first << " " << it->second << endl;
//	}
//
//	return 0;
//}


//int main11()
//{
//	int inputData;
//	int num = 0;
//	cin >> inputData;
//	int countArr[100] = { 0 };
//	while (inputData)
//	{
//		if (countArr[inputData % 10] == 0)
//		{
//			countArr[inputData % 10]++;//更新，遇到下次相同的数会跳过
//			num = num * 10 + inputData % 10;
//		}
//		inputData /= 10;
//	}
//	cout << num << endl;
//	system("pause");
//	return 0;
//}


int lastWordLength(string str, int len)
{
	
	int count = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
			count++;
		else
			break;
	}
	return count;
}

//有错误
int NumberofChar(string str, int len)
{
	int iCount = 0;
	for (int i = 0; i<len; i++)
	{
		if (str[i] > '0' && str[i] < '127')
			iCount++;
		i++;
	}
	return iCount;
}


//int main(void)
//{
//	int a[128] = { 0 };
//	char input;
//	int CharCount = 0;
//	while (cin >> input)
//		a[input]++;
//
//	for (int i = 0; i<128; i++)
//	{
//		if (a[i])
//			CharCount++;
//	}
//	cout << CharCount << endl;
//	system("pause");
//	return 0;
//}

//参考了kiss90的写法，修改了一下；

//int main(void)
//{
//	string str;
//	set<char> s;
//	while (getline(cin, str))
//	{
//		for(int i=0; i<str.length(); i++)
//			s.insert(str[i]);//把每个字符插入到set容器s里
//			//计算set容器的元素个数，set的特点是元素必须是唯一的，
//			//重复的元素会被忽略
//		cout << s.size() << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main(void)
//{
//	char ch;
//	set<char> s;
//	while (cin>>ch)
//	{
//		if (ch >= 0 && ch <= 127)
//			s.insert(ch);
//	}
//	cout << s.size() << endl;
//	system("pause");
//	return 0;
//}


int NumReverse1(void)
{
	int inputData;
	int arr[100] = { 0 };
	int i = 0;
	int count = 0;
	cin >> inputData;
	while (inputData)
	{
		arr[i++] = inputData % 10;
		inputData /= 10;
		count++;
	}

	for (i = 0; i < count; i++)
	{
		cout << arr[i];
	}

	cout << endl;
	return 0;
}

int NumReverse(void)
{
	int inputData;
	cin >> inputData;
	while (inputData)
	{
		int out = inputData % 10;
		inputData /= 10;
		cout << out;
	}
	cout << endl;
	system("pause");
	return 0;
}


//int main()
//{
//	string str;
//	getline(cin, str);
//	int len = str.size(), i;
//	for (i = len - 1; i >= 0; i--)
//	{
//		cout << str[i];
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//
//}

void strReverse(string str, int len)
{
	//int j;
	//for(int i=0; i < len/2; i++)
	//{ 
	//	j = len - i - 1;
	//	swap(str[i], str[j]);
	//}

	//for (int i = 0; i < len; i++)
	//	cout << str[i];

	for (int i = len - 1; i >= 0; i--)
		cout << str[i];
}


void strReverse1(string str, int len)
{
	reverse(str.begin(), str.end());
	for (int i = len - 1; i >= 0; i--)
		cout << str[i];
}
void sentenceReverse1(char *str, int len)
{
	char *p = str;
	while(p = strrchr(str, ' '))
	{
		cout << p + 1 << " ";
		*p = '\0';
	}
	cout << p[0];
		
}



int main22(void)
{
	//char str[1024];
	//gets_s(str, 1024);
	//int len = strlen(str);

	string str;
	stack<string> moban;
	while (cin >> str)
	{
		moban.push(str);
	}
	
	while (moban.size() != 1)
	{
		cout << moban.top() << " ";
		moban.pop();
	}

	cout << moban.top() << endl;
	system("pause");
	return 0;
}

int main3(void)
{
	string str;
	int num;
	set<string> t;
	cin >> num;
	while (num)
	{
		while (cin >> str)
		{
			t.insert(str);
		}
		num--;
	}
	set<string>::iterator it = t.begin();
	for (; it != t.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;

}

double SquareRoot(double data)
{
	double x1, x2 = 1.0;
	do 
	{
		x1 = x2;
		x2 = (x1 + data / x1) / 2;
	} while (fabs(x2 - x1) > 1e-5);
	return x2;
}

double CubeRoot(double data)
{
	double temp;
	double x = 0.0;

	if (data < 0)
		temp = -data;
	else
		temp = data;
	while (x*x*x <= temp)
	{
		x += 0.1;
	}

	if (data < 0)
		x = -x;

	return x;
}

//int main(void)
//{
//
//	double inputData;
//	cin >> inputData;
//	cout<<CubeRoot(inputData)<<endl;
//	//cout<<SquareRoot(inputData)<<endl;
//	system("pause");
//	return 0;
//}





