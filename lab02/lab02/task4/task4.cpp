#include "pch.h" 
#include <iostream> 
using namespace std;
bool voo(int, int&, bool&, bool&);
int main()
{
	cout << "enter the number ";
	int chis;
	cin >> chis;
	int ost;
	bool chet=false, poloj=false, srav;
	srav = voo(chis, ost, chet, poloj);
	if (poloj) cout << "The number is positive \n";
	else cout << "The number is negative \n";
	if (chet) cout << "The number is even \n";
	else cout << "The number is odd \n";
	cout << "The remainder of the division by 5 is " << ost << endl;
	if (srav) cout << "Number greater than 10 \n";
	else cout << "Number not more than 10";
}
bool voo(int chis1, int& ost1, bool& chet1, bool& poloj1)
{
	ost1 = chis1 % 5;
	if (chis1 % 2==0) chet1 = true;
	if (chis1 > 0) poloj1 = true;
	if (chis1 > 10) return true;
	else return false;
}