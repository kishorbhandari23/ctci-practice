#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

bool check_substr(const string &str1, const string &str2)
{
	if ((str1.length() == str2.length())&& (str1.length() >0))
	{
		string str1str1 = str1 + str1;
		if (str1str1.find(str2))
			return true;
	}
	return false;
}


int main()
{
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	if (check_substr(str1, str2))
		cout << "Rotated String" << endl;
	else
		cout << "Not Rotated String" << endl;

	str1 = "waterbottle";
	str2 = "apple";
	if (check_substr(str1, str2))
		cout << "Rotated String" << endl;
	else
		cout << "Not Rotated String" << endl;
}

