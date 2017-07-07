#include <iostream>
#include <string>
using namespace std;

#if 0
void swap_with_zero(int* array, int len, int &n)
{
	swap(array[0], n);
}

void sort(int* array, int len)
{

	for (int i = len - 1; i >= 0; i--)
	{
		int max = array[i];
		int flag = i;	//每一轮中最大元素的下标
		for (int j = i - 1; j >= 0; j--)
		{
			if (max < array[j])
			{
				max = array[j];
				flag = j;
			}
		}
		//if (flag != i)
		//{
			swap_with_zero(array, len, array[flag]);
			swap_with_zero(array, len, array[i]);
		//}

	}
}
int main(void)
{

	int a[10] = { 3, 100, 2, 4, 5, 0, 1, 7, 9, 6 };
	/*for (int i = 0; i < 10; i++)
		cout << a[i];*/
	sort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}

#endif

#if 0
void replaceSpace(char *str, int length)
{
	if (str == NULL || length <0 )
	{
		return;
	}

	int originalLength = 0;
	int spaceNum = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		originalLength++;
		if (str[i] == ' ')
			spaceNum++;
	}
	int newLength = originalLength + 2 * spaceNum;

	if (newLength > length)
		return;

	int newIndex = newLength;
	int oldIndex = originalLength;
	while (oldIndex >= 0 && newLength > oldIndex)
	{
		if (str[oldIndex] == ' ')
		{
			str[newIndex--] = '0';
			str[newIndex--] = '2';
			str[newIndex--] = '%';
		}
		else
		{
			str[newIndex--] = str[oldIndex];	
		}
		oldIndex--;
	}
}

int main(void)
{
	char str[128] = { "We Are Happy My Name is yuyang" };
	int len = strlen(str);
	replaceSpace(str, 128);

	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
	system("pause");
	return 0;
}

#endif


#if 0
long long reverseAdd(long long a, long long b)
{
	long long temp;
	long long sumA = 0;
	long long sumB = 0;
	if ((a >= 1 && a <= 7000) && (b >= 1 && b <= 7000))
	{
		while (a)
		{
			temp = a % 10;
			sumA = sumA * 10 + temp;
			a /= 10;
		}
		while (b)
		{
			temp = b % 10;
			sumB = sumB * 10 + temp;
			b /= 10;
		}
		return sumA + sumB;
	}
	else return -1;
}

int main(void)
{
	long a, b;
	while(cin >> a >> b)
		cout << reverseAdd(a, b);
	system("pause");
	return 0;
}
#endif

#if 0
using namespace std;
char* fun(char *str, int len)
{
	char init[7] = "123456";
	int i = 0;
	while (str[i] != '\0')
	{
		switch(str[i])
		{
            case 'L':
				swap(init[0], init[4]);
				swap(init[1], init[5]);
				swap(init[4], init[5]);
				i++;
				break;
			case 'R':
				swap(init[0], init[5]);
				swap(init[1], init[4]);
				swap(init[5], init[4]);
				i++;
				break;

			case 'F':
				swap(init[2], init[5]);
				swap(init[3], init[4]);
				swap(init[2], init[3]);
				i++;
				break;

			case 'B':
				swap(init[2], init[4]);
				swap(init[3], init[5]);
				swap(init[2], init[3]);
				i++;
				break;

			case 'A':
				swap(init[0], init[2]);
				swap(init[1], init[3]);
				swap(init[0], init[1]);
				i++;
				break;

			case 'C':
				swap(init[0], init[2]);
				swap(init[1], init[3]);
				swap(init[2], init[3]);
				i++;
				break;
			default:
				i++;
				break;
		}

	}

	for (int i = 0; init[i] != '\0'; i++)
		cout << init[i];
	return init;

}


int main()
{
	//string str;
	//getline(cin, str);
	//int len = str.length();
	char str[50];
	gets_s(str);
	int len = strlen(str);
	char *p = fun(str, len);


	system("pause");
	return 0;

}

#endif

int fab(int n)
{
	if (n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else return fab(n - 1) + fab(n - 2);
}

int fun(int n)
{
	int i = 0;
	do
	{
		i++;
	} while (!(fab(i) > n && fab(i - 1) < n));
	return fab(i);
}

int main1(void)
{
	int n = 1000;
	cout << fun(n);
	//cout << fab(3) << endl;;
	system("pause");
	return 0;
}


int main2(void)
{
	int a = 0, b = 0, c = 0;
	int sum = 0;
	for (int i = 100; i<1000;i++)
	{
		a = i % 10;
		b = i % 100 / 10;
		c = i / 100;
		if (a*a*a + b*b*b + c*c*c == i)
		{
			sum += i;
			cout << "第一个水仙花数： " << i << endl;
		}
	}
	cout << "水仙花总和为： " << sum << endl;
	system("pause");
	return 0;
}
int main3(void)
{
	int a, b, c;
	int sum = 0;
	int j = 0;
	for (int i = 100; i<1000; i++)
	{
		a = i % 10;
		b = i % 100 / 10;
		c = i / 100;
		if (a*a*a + b*b*b + c*c*c == i)
		{
			sum += i;
			j++;
			cout << "第" << j << "个水仙花数： " << i << endl;
		}
	}
	cout << "水仙花总和为： " << sum << endl;
	system("pause");
	return 0;
}

int main(void)
{
	int input1, input2, input3;
	char ch;
	int num;
	int a[100];
	cin >> input1 >> ch >> input2 >>ch >> input3;
	if (input1 < 0 || input2 < 0 || input3 < 0 || ch != ',' ||input1 == input2 || input1 == input3 || input2 == input3)
	{
		return -1;
	}

	if (input1>input2)
		num = input1;
	else num = input2;

	if (num < input3)
		num = input3;
	else
		num = num;
	cout << num << endl;
	int i = 0;
	a[i++] = input1;
	a[i++] = input2;
	a[i++] = input3;
	a[i++] = input1 * 10 + input2;
	a[i++] = input1 * 10 + input3;
	a[i++] = input2 * 10 + input1;
	a[i++] = input2 * 10 + input3;
	a[i++] = input3 * 10 + input1;
	a[i++] = input3 * 10 + input2;

	a[i++] = input1 * 100 + input2 * 10 + input3;
	a[i++] = input1 * 100 + input3 * 10 + input2;

	a[i++] = input2 * 100 + input1 * 10 + input3;
	a[i++] = input2 * 100 + input3 * 10 + input1;

	a[i++] = input3 * 100 + input1 * 10 + input2;
	a[i++] = input3 * 100 + input2 * 10 + input1;


	for (int i = 0; i < 14; i++)
	{
		for (int j = i + 1; j < 15; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
		
	}
	for (int i = 0; i < 15; i++)
	{
		cout << a[i] << " ";
	}

	
	system("pause");
	return 0;
}