//Programmer: David Szatkowski
//File: postfix.cpp
//CS 3100
//2.28.2018
//Infix to Postfix Converter

#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

using namespace std;

string postfix(const string infix)
{
	int n = infix.length();
	string postfix = "";
	int state = 1;
	stack<char> opstack;
	int i = 0;
	cout << "flag 1";
	while(i < n)
	{
		if(!opstack.empty())
			cout << "opstack " << opstack.top();
		switch(state)
		{
			case 1:
				if(infix.at(i) == '-')
				{
					state = 2;
					postfix.push_back(infix.at(i));
				}
				else if(isdigit(infix.at(i)))
				{
					state = 3;
					postfix.push_back(infix.at(i));
				}
				else if(infix.at(i) == '.')
				{
					postfix.push_back(infix.at(i));
					state = 4;
				}
				else if(infix.at(i) == '(')
				{
					opstack.push(infix.at(i));
					postfix.push_back(' ');
				}
				else
					state = 0;
				break;
			case 2:
				if(isdigit(infix.at(i)))
				{
					state = 3;
					postfix.push_back(infix.at(i));
				}
				else if(infix.at(i) == '.')
				{
					postfix.push_back(infix.at(i));
					state = 4;
				}
				else if(infix.at(i) == '(')
				{
					postfix.push_back(' ');
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '+' || infix.at(i) == '-')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x' || opstack.top() == '+' || opstack.top() == '-')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '*' || infix.at(i) == '/' || infix.at(i) == 'x')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == ')')
				{
					postfix.push_back(' ');
					if(!opstack.empty())
					{
						while(opstack.top() != '(');
						{
							postfix.push_back(opstack.top());
							opstack.pop();
							postfix.push_back(' ');
						}
					}
					if(opstack.empty())
						cout << "Error: Missing '('";
					else if(opstack.top() == '(')
						opstack.pop();
					else
						cout << "Error: Should not happen";
					state = 5;
				}
				else
					state = 0;
				break;
			case 3:
				if(isdigit(infix.at(i)))
				{
					postfix.push_back(infix.at(i));
				}
				else if(infix.at(i) == '.')
				{
					postfix.push_back(infix.at(i));
					state = 4;
				}
				else if(infix.at(i) == '(')
				{
					postfix.push_back(' ');
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '+' || infix.at(i) == '-')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x' || opstack.top() == '+' || opstack.top() == '-')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '*' || infix.at(i) == '/' || infix.at(i) == 'x')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == ')')
				{
					postfix.push_back(' ');
					if(!opstack.empty())
					{
						cout << "FLAG " << opstack.top();
						while(!(static_cast<char>(opstack.top()) == static_cast<char>('(')));
						{
							cout << "run?" << opstack.top();
							postfix.push_back(opstack.top());
							opstack.pop();
							postfix.push_back(' ');
						}
					}
					if(opstack.empty())
					{
						cout << "Error: Missing '('";
					}
					else if(opstack.top() == '(')
						opstack.pop();
					else
						cout << "Error: Should not happen";
					state = 5;
				}
				else
					state = 0;
				break;
			case 4:
				if(isdigit(infix.at(i)))
				{
					postfix.push_back(infix.at(i));
				}
				else if(infix.at(i) == '(')
				{
					postfix.push_back(' ');
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '+' || infix.at(i) == '-')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x' || opstack.top() == '+' || opstack.top() == '-')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '*' || infix.at(i) == '/' || infix.at(i) == 'x')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == ')')
				{
					postfix.push_back(' ');
					if(!opstack.empty())
					{
						while(opstack.top() != '(');
						{
							postfix.push_back(opstack.top());
							opstack.pop();
							postfix.push_back(' ');
						}
					}
					if(opstack.empty())
						cout << "Error: Missing '('";
					else if(opstack.top() == '(')
						opstack.pop();
					else
						cout << "Error: Should not happen";
					state = 5;
				}
				else
					state = 0;
				break;
			case 5:
				if(infix.at(i) == '+' || infix.at(i) == '-')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x' || opstack.top() == '+' || opstack.top() == '-')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == '*' || infix.at(i) == '/' || infix.at(i) == 'x')
				{
					postfix.push_back(' ');
					while(opstack.top() == '*' || opstack.top() == '/' || opstack.top() == 'x')
					{
						postfix.push_back(opstack.top());
						opstack.pop();
						postfix.push_back(' ');
					}
					opstack.push(infix.at(i));
					state = 1;
				}
				else if(infix.at(i) == ')')
				{
					postfix.push_back(' ');
					if(!opstack.empty())
					{
						while(opstack.top() != '(');
						{
							postfix.push_back(opstack.top());
							opstack.pop();
							postfix.push_back(' ');
						}
					}
					if(opstack.empty())
						cout << "Error: Missing '('";
					else if(opstack.top() == '(')
						opstack.pop();
					else
						cout << "Error: Should not happen";
					state = 5;
				}
				else
					state = 0;
				break;
		}
		i++;
	}
	if(state != 3 && state != 4 && state != 5)
		cout << "Error: Invalid Input";
	return postfix;
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
