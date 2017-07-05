#if 0
#include <iostream>

using namespace std;

int main(void)
{
	int N,a[1001] = {0};
	int i, t;
	cin >> N;
	for(i=0; i<N; i++)
	{
		cin>>t;
		if(a[t] == 0)
		{
			a[t] = t;
		}
	}
	for(i=0; i<1001; i++)
	{
		if(a[i] != 0)
			cout<<a[i]<<endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    list <int> L;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        L.push_back(t);
    }
    L.sort();
    L.unique();
    cout<<L.size()<<endl;
    for(list <int> ::iterator iter=L.begin();iter!=L.end();iter++)
        cout<<*iter<<" ";cout<<endl;
    return 0;
}
#endif

#if 0 
#include <iostream>

using namespace std;

int main(void)
{
	int num,N;
	while(cin>>num)
	{
		int a[1001] ={0};
		while(num--)
		{
			cin>>N;
			a[N] = 1;
		}
		for(int i=0; i<1001; i++)
		{
			if(a[i])
				cout<<i<<endl;
		}	
	}
	return 0;
	
}
#endif

#include <iostream>
#include <string>
using namespace std;

//主要明白substr(起始位置，截取子字符窜个数)函数即可
#include <iostream>
#include <string>
using namespace std;
void fuck(string str) {
    if (str == "")
        return;
    if (str.size() <= 8) {
        str.append(8 - str.size(), '0');
        cout << str << endl;
        return;
    }
    cout << str.substr(0, 8) << endl;
    fuck(str.substr(8, str.size()));
}
int main() {
    string str1, str2;
    cin >> str1 >> str2;	//cin忽略不可见字符，如空格 tab
    fuck(str1);
    fuck(str2);
    return 0;
}






