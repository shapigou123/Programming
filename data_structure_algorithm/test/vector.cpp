#include <vector>
#include <string>
#include <iostream>
using std::vector;
using namespace std;

#if 0
int main1()
{
    string str;
    getline(cin, str);
    for(int i=0; str[i] != '\0'; i++)
    {
        //if(islower(str[i]))
        //{
           str[i] = toupper(str[i]);
        //}

    }

    cout << "´ó¼ÒºÃ" << endl;
    return 0;
}
#endif

int main(void)
{
	//string str1("hello world");
	vector<char> str;
	str.push_back('h');
	str.push_back('e');
	str.push_back(' ');
	str.push_back('q');
	str.push_back('w');
    vector<char>::iterator iter = str.begin();
    for(; iter != str.end(); iter++)
    {
		if(isspace(*iter))
			continue;
		else
		{
			*iter = toupper(*iter);
			cout<<*iter;
		}
       
    }
	cout<<endl;

    return 0;
}
