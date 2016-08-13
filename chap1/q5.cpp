#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

bool one_edit_away(string str1, string str2)
{
	int match=0,i=0;
	int str1_len, str2_len,big_len;
	str1_len = str1.length();
	str2_len = str2.length();


	if (abs(str1_len - str2_len) > 1)
		return false;

	if (str2_len > str1_len) {
		swap(str1, str2);
		swap(str1_len, str2_len);
	}

	while ((str1[i] == str2[i])&&(i<str2_len))
	{
		match++,i++;
	}

	while ((str1[i+1] == str2[i]) && ((i+1)<str1_len))
	{
		match++, i++;
	}
	while (((i + 1)<str2_len) && (str1[i+1] == str2[i+1])) //for pale & bale, kind of string
	{
		match++, i++;
	}

	if ((str1_len - match) <= 1)
		return true;
	else
		return false;
}

int main()
{
	string str1, str2;
	cout << "Enter the first string"<< endl;
	cin >> str1;
	cout << "Enter the Second string" << endl;
	cin >> str2;
	if (one_edit_away(str1, str2))
		cout << "The given strings are one edit away" << endl;
	else
		cout << "The given strings are not one edit away" << endl;
}