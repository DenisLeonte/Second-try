/*
V 1.2.2 Changelog
Made that the lexer can now recognize numbers
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream in("script.denis");
map <string, float> var;
string operators = ":=+-/*%";
string f[] = { "var","print","assign" };

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

//The main function that will understand expressions
void lexer()
{
	vector <string> op;
	string aux, arg1, arg2, arg3, c;
	float arg2x, arg3x;
	in >> aux;
	arg1 = aux;
	while(strcmp(aux.c_str(),"|") != 0)
	{
		in >> aux;
		op.push_back(aux);
	}
	float s,prec;
	if (op[0] == "=")
	{
		arg2 = op[1];
		try
		{
			prec = stoi(arg2);
		}
		catch (...)
		{
			prec = var[arg2];
		}
		for (int i = 2; i < op.size()-2; i += 2)
		{
			arg3 = op[i + 1];
			c = op[i];
			try
			{
				arg3x = stoi(arg3);
				s = operations(prec, arg3x, c[0]);
			}
			catch(...)
			{
				s = operations(prec, var[arg3], c[0]);
			}
			prec = s;
		}
		var[arg1] = prec;
	}
}

//The main input function
void IO(string op)
{
	//declaring a variable
	if (strcmp(op.c_str(), f[0].c_str()) == 0)
	{
		string name;
		float value;
		in >> name >> value;
		var[name] = value;
	}
	//print a variable
	if (strcmp(op.c_str(), f[1].c_str()) == 0)
	{
		string ax;
		in >> ax;
		cout << var[ax] << endl;
	}
	//Gateway to the lexer
	if (strcmp(op.c_str(), f[2].c_str()) == 0)
	{
		lexer();
	}
}

int main()
{
	string io;
	while (in>>io)
		IO(io);
	return 0;
}