#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<char> fun(const string &str)
{
	vector<char> vec;
	map<char, int> myMap;
	for(int i=0; i<str.size(); i++)
		myMap[str[i]]++;

	for(map<char, int>::iterator iter=myMap.begin(); iter!= myMap.end(); iter++)
	{
		if(iter->second > 2)
		{
			//char c = iter->second;
			vec.push_back(iter->second + '0');
			vec.push_back(iter->first);
		}
		else if(iter->second <=2)
		{
			while(iter->second)
			{
				vec.push_back(iter->first);
				iter->second--;
			}
		}
	}
	return vec;
}

int main()
{
	vector<char> vec;
	vec = fun("aaabbccccccdderfad");
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i];
	cout <<endl;
}