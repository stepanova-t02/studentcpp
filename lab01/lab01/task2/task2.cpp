#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "What is your name? \n";
	char x[80];
	cin >> x;
	cout << "enter your birthday date \n";

	int a, b, c;

	cin >> a >> b >> c;

	int god;

	god = 2018 - c - 1;
	if (b < 11)
	{
		god = god + 1;
	}
	else if (b > 11)
	{
		god = god;
	}
	else if (a <= 7)
	{
		god = god + 1;
	}

	cout << "Hello, ";  cout << x; cout << " You're "; cout << god; cout << " years old.";
}