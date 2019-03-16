#include "pch.h"
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compareBM(string s1, string s2)
{
	if (s1.length() >= s2.length())
		return true;
	else
		return false;
}
string refixed(string d)
{
	string::iterator it = d.begin();
	while (it != d.end())
	{
		for (string::iterator helper = it + 1; helper != d.end(); helper++) {
			if (*it == *helper)
			{
				d.erase(helper);
				helper--;
				// 为了使得最后一次字符被删除时，check2不会超出input1的范围。
			}
		}
		it++;
	}
	return d;
}
string commonChars(const string& s1, const string& s2)
{
	bool c;
	string b=s1,d=s1;
	c=compareBM(s1, s2);
	int a[100] = { 0 };
	int k=0;
	if (c == true)
	{
		for (unsigned int i=0;i<s1.length();i++)
		{
			for (unsigned int j = 0; j<s2.length(); j++)
			{
				if (s1[i] == s2[j])
				{
					a[k] = i;
						k++;
				}
			}
		}
					
	}
	else
	{
		for (unsigned int i = 0; i < s2.length(); i++)
		{
			for (unsigned int j = 0;j< s1.length(); j++)
			{
				if (s2[i] == s1[j])
				{
					a[k] = i;
					k++;
				}
			}
		}
	}
	if (k == 0)
		return "No common characters";
	if (c == true)
		b = s1;
	else b = s2;
	for (int i = 0; i < k; i++)
	{
		d[i] = b[a[i]];
	}
	for (int i = k; i < d.length(); i++)
	{
		d[i] = '\0';
	}
	d = refixed(d);
	return "The common characters are "+d;
}
int main()
{
	string s1, s2;
	cout << "Enter a string s1:";
	cin >> s1;
	cout << endl;
	cout << "Enter a string s2:";
	cin >> s2;
	cout<<commonChars(s1, s2);
	return 0;
}
