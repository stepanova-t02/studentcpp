#include "pch.h" 
#include <iostream> 
using namespace std;
bool isExceeded(int, int&);
int main()
{
	cout << "Type the number to calculate factorial: ";
	int a; //  а - число, для которого нужно посчитать факториал
	cin >> a; 
	int stepnumber1=0;
	bool b;
	b = isExceeded(a, stepnumber1);
	cout << "Did the factorial exceed the value? ";
	if (b) 
	{
		cout << "YES \n";
		cout << "The step number is ";
		cout << stepnumber1;

	}
	else cout << "NO \n"; 
}
bool isExceeded(int numToCalculateFactorial, int& stepNumber)
{
	cout << "Number to compare: ";
	int c, d = 1; // с-число для сравнения d- факториал числа а 
	cin >> c;
	for (int i = 1; i < 1 + numToCalculateFactorial; i++)
	{
		d *= i;
		if (d > c) stepNumber++;
	}
	stepNumber = numToCalculateFactorial - stepNumber;
	if (d > c) return true;
	else return false;
}