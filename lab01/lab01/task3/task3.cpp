#include "pch.h"
# include <iostream>
using namespace std;
int main()
{
	int a = 21;
	cout << "Hi. Try to guess a number. \n";
	int r = 0;
	int m = 1;
	while (m != 0)
	{
		r = r + 1;
		cout << r;
		cout << " try: ";
		int b;
		cin >> b;
		if (a == b)
		{
			cout << "Answer: yes";
			m = 0;
		}
		else if (a > b)
		{
			cout << "No, Greater \n";

		}
		else if (a < b)
		{
			cout << "No, Less \n";
		}
	}
}