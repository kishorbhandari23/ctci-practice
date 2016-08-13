#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

bool one_edit_away(string str1, string str2)
{
	int match=0,i=0;
	int str1_len, str2_len;

	if (abs(str1_length() - str2_length()) > 1)
		return false;

	if (str2_len > str1_len) //take str1 as bigger string
		swap(str1, str2);

	while ((str1[i] == str2[i])&&(i<str2_len)) //till the matches are found continue ad increase match 
	{
		match++,i++;
	}

	while ((str1[i+1] == str2[i]) && ((i+1)<str1_len)) //Now see if leaving one character in bigger string , all other characters are equal
	{
		match++, i++;
	}
	while (((i + 1)<str2_len) && (str1[i+1] == str2[i+1])) //for pale & bale, kind of string, everything except one charcter must be equal
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