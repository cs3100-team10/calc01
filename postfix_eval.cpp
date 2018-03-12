//Programmer: David Szatkowski
//File: postfix.cpp
//CS 3100
//2.28.2018
//Infix to Postfix Converter

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <ctype.h>
#include <sstream>
#include <algorithm>

using namespace std;

bool isFloat(string input)
{
	istringstream istream(input);
	float f;
	istream >> noskipws >> f;
	return istream.eof() && !istream.fail();
}

bool isOp(string input)
{
	list<string> OpList = 
	{"+", "x", "*", "/", "-"};
	list<string>::iterator it;
	it = find(OpList.begin(), OpList.end(), input);
	if(it != OpList.end())
		return true;
	else
		return false;
}

string postfix_eval(const string input)
{
	stringstream stream(input);
	stack<string> opstack;
	while(1)
	{
		string hold;
		float f;
		stream >> hold;
		if(isFloat(hold))
			
	}
}

int main(int argc, char** argv) 
{
	string s, out;
	cout << "Input Infix String:\n";
	cin >> s;
	out = postfix(s);
	cout << out;
	
	return 0;
}
