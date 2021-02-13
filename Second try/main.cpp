/*
V 1.1 Changelog
Made the IO better and separated the operations and the input
Still have to do the loop
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <map>

using namespace std;

ifstream in("script.denis");
map <string, float> var;
string operators = ":=+-/*%";
string functions[] = { "var","print" };

//The operations hub function
float operations(float val1, float val2, char op)
{
	if (strchr(operators.c_str(), op))
	{
		switch (op)
		{
		case '+':
			return val1 + val2;
			break;
		case '-':
			return val1 - val2;
			break;
		case '*':
			return val1 * val2;
			break;
		case '/':
			return val1 / val2;
			break;
		case '%':
			int val3 = val1, val4 = val2;
			return val3 % val4;
			break;
		}
	}
}

//The main input function
void IO()
{
	string op;
	in >> op;
	//print
	if (strcmp(op.c_str(), functions[1].c_str()) == 0)
	{
		float a, b;
		char x;
		in >> a >> x >> b;
		cout << operations(a, b, x) << endl;
	}
}

int main()
{
	string op;
	IO();
	return 0;
}