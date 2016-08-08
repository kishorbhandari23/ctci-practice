
#include "stdafx.h"


#include<iostream>
#include <map>
#include<string>
using namespace std;

bool isUnique(string input_str)
{
	map<string, int> m;
	for (int i = 0; i<input_str.length(); i++)
	{
		if (m[input_str.substr(i, 1)] == 0) //if the character is already not in hash table, put it in hash table
			m[input_str.substr(i, 1)] = 1; //'1' to indicate that, this character now is in hash table
		else
			return false;
	}
	return true;
}


int main()
{
	string input_str;
	cin >> input_str;
	if (isUnique(input_str))
		cout << "This string has all unique characters";
	else
		cout << "This is not a unique string";
}