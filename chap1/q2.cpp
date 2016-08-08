#include "stdafx.h"


#include<iostream>
#include <map>
#include<string>
using namespace std;

bool isPermutation(string input_str1, string input_str2)
{
	if (input_str1.length() != input_str2.length())
		return false;

	map<string, int> m1, m2;

	for (int i = 0; i<input_str1.length(); i++)
	{
		m1[input_str1.substr(i, 1)]++;
		m2[input_str1.substr(i, 1)]++;
	}

	for (int i = 0; i<input_str1.length(); i++)
	{
		if (m1[input_str1.substr(i, 1)] != m2[input_str2.substr(i, 1)])
			return false;
	}
	return true;
}


int main()
{
	string input_str1, input_str2;
	cin >> input_str1 >> input_str2;

	if (isPermutation(input_str1, input_str2))
		cout << "Permutation string";
	else
		cout << "Not a permutation string";
}