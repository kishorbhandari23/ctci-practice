#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

string string_compress(const string& str)
	{
	int count_char=0,j;
	string prev_char, current_char, new_string;

	for(int i=0;i<str.length();)
	{
		count_char=0;
		current_char = str.substr(i,1);
	    
		while(str.substr(i++,1) == current_char)
		count_char++;
		new_string += current_char;
		new_string.append(std::to_string(count_char));
	}

    //if(new_string.length() < str.length() )
	return new_string;
	//else
	//return str;
    
    }
	
