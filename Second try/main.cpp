#include <iostream>
#include <fstream>
#include <string.h>
#include <map>

using namespace std;

ifstream in("script.denis");
map <string, float> var;
string operators = ":=+-/*%";

void inputFromFile()
{
	char op;
	int val1,val2;
	in >> val1 >> op >> val2;
	if (strchr(operators.c_str(), op))
	{
		switch (op)
		{
		case '+':
			cout << val1 + val2;
			break;
		case '-':
			cout << val1 - val2;
			break;
		case '*':
			cout << val1 * val2;
			break;
		case '/':
			cout << val1 / val2;
			break;
		case '%':
			cout << val1 % val2;
			break;
		}
	}
}

int main()
{
	inputFromFile();
	return 0;
}