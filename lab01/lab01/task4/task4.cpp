#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int m = 1;
	while (m != 0)
	{
		cout << "Hello, my dear. What are the numbers?\n";
		float a, b;
		cout << "Number 1:";
		cin >> a;
		cout << "Number 2:";
		cin >> b;
		cout << "What do you want to do?\n";
		cout << " 1. + \n 2. -\n 3. *\n 4. /\n";
		int c;
		cout << "Your answer :";
		cin >> c;
		float x;
		if (c == 1) { x = a + b; }
		if (c == 2) { x = a - b; }
		if (c == 3) { x = a * b; }
		if (c == 4) { x = a / b; }
		cout << "Result: ";
		cout << x;
		cout << " \n";
		cout << "Do you want to try again? y/n \n";
		char q;
		cin >> q;
		if (q == 'y') { m = 1; }
		else { m = 0; }
	}
}