#include "pch.h"
#include <iostream>
#include <string>
#include <locale>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
	T* s;
	const int size;
	int top;
public:
	Stack(int maxSize);
	~Stack();
	const T& Peek(int) const;
	void push(const T&);
	inline T pop();
	string PlayerName1, PlayerName2;
	char win = '-';



	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}


	void show_cells() {
		system("cls");

		cout << "Номер клеточки:\n" << endl;
		//Номера клеток для того, чтобы игрок знал куда ходить
		cout << ' ' << 1 << ' ' << '|' << ' ' << 2 << ' ' << '|' << ' ' << 3 << ' ' << endl;
		cout << ' ' << 4 << ' ' << '|' << ' ' << 5 << ' ' << '|' << ' ' << 6 << ' ' << endl;
		cout << ' ' << 7 << ' ' << '|' << ' ' << 8 << ' ' << '|' << ' ' << 9 << ' ' << "\n" << endl;

		cout << "Текущая ситуация :\n" << endl;
		//Текущая ситуация на поле 
		cout << ' ' << Peek(0) << ' ' << '|' << ' ' << Peek(1) << ' ' << '|' << ' ' << Peek(2) << ' ' << endl;
		cout << ' ' << Peek(3) << ' ' << '|' << ' ' << Peek(4) << ' ' << '|' << ' ' << Peek(5) << ' ' << endl;
		cout << ' ' << Peek(6) << ' ' << '|' << ' ' << Peek(7) << ' ' << '|' << ' ' << Peek(8) << ' ' << "\n" << endl;
	}


	void make_move(int num)
	{
		setlocale(LC_ALL, "Rus");
		char f;

		if (num == 1) {
			cout << PlayerName1;
			//Если аргумент = 1, то выводится имя первого игрока (то есть он будет ходить)
			cout << ", введите номер ячейки, чтобы сделать ход: ";
			int cell;
			cin >> cell; //Игрок должен указать номер клеточки
			cout << "\n";
			while (cell > 9 || cell < 1 || Peek(cell - 1) == 'O' || Peek(cell - 1) == 'X')
			{
				//Проверка на правильность (клеточка не занята и ее номер не <1 и не >9)
				cout << "ВВЕДИТЕ КОРРЕКТНЫЙ (1-9) ИЛИ ПУСТОЙ НОМЕР КЛЕТОЧКИ, ЧТОБЫ СДЕЛАТЬ ХОД: ";
				cin >> cell; //Если проверка не пройдена, то игрок должен еще раз ввести номер клеточки
				cout << "\n";
			}
			FUNCTION(cell, 1);
		}
		else
		{
		a:	int number = getRandomNumber(0, 8);
			f = Peek(number);
			if (f == 'X' || f == 'O')
			{
				goto a;
			}

			else {
				FUNCTION(number + 1, 2);
			}
		}
	}

	void result()
	{
		setlocale(LC_ALL, "Rus");
		if (win == 'X')
		{
			cout << PlayerName1 << " победил!  " << endl;

		}
		else if (win == 'O')
		{
			cout << "Компьютер победил!  " << PlayerName1 << ", вы проиграли" << endl;
		}
		else
		{
			cout << "НИЧЬЯ!!!" << endl;
		}
	}

	void FUNCTION(int k, int num) //помещение хода в стек
	{
		char* R = new char[20];
		for (int i = 0; i < 9; i++)
		{
			R[i] = Peek(i);
		}
		if (num == 1)
		{
			R[k - 1] = 'X';
		}
		else
		{
			R[k - 1] = 'O';
		}
		while (top != 0)
		{
			pop();
		}
		for (int i = 0; i < 9; i++)
		{
			push(R[i]);
		}
	}

	char check()// проверка победы  
	{
		if ((Peek(0) == Peek(1) && Peek(0) == Peek(2) && Peek(0) == 'X') || (Peek(0) == Peek(1) && Peek(0) == Peek(2) && Peek(0) == 'O')) // по горизонтали 1-2-3
		{
			return Peek(0);
		}


		else if ((Peek(3) == Peek(4) && Peek(3) == Peek(5) && Peek(3) == 'X') || (Peek(3) == Peek(4) && Peek(3) == Peek(5) && Peek(3) == 'O')) // по горизонтали 4-5-6
		{
			return Peek(3);
		}
		else if ((Peek(6) == Peek(7) && Peek(6) == Peek(8) && Peek(6) == 'X') || (Peek(6) == Peek(7) && Peek(6) == Peek(8) && Peek(6) == 'O')) // по горизонтали 7-8-9
		{
			return Peek(6);
		}
		else if ((Peek(2) == Peek(4) && Peek(4) == Peek(6) && Peek(2) == 'X') || (Peek(0) == Peek(4) && Peek(4) == Peek(8) && Peek(0) == 'X') || (Peek(2) == Peek(4) && Peek(4) == Peek(6) && Peek(2) == 'O') || (Peek(0) == Peek(4) && Peek(4) == Peek(8) && Peek(0) == 'O')) // по диагоналям 3-5-7 и 1-5-9
		{
			return Peek(4);
		}
		else if ((Peek(0) == Peek(3) && Peek(0) == Peek(6) && Peek(0) == 'X') || (Peek(0) == Peek(3) && Peek(0) == Peek(6) && Peek(0) == 'O')) //по вертикали 1-4-7
		{
			return Peek(0);
		}
		else if ((Peek(1) == Peek(4) && Peek(1) == Peek(7) && Peek(1) == 'X') || (Peek(1) == Peek(4) && Peek(1) == Peek(7) && Peek(1) == 'O')) //по вертикали 2-5-8
		{
			return Peek(1);
		}
		else if ((Peek(2) == Peek(5) && Peek(2) == Peek(8) && Peek(2) == 'X') || (Peek(2) == Peek(5) && Peek(2) == Peek(8) && Peek(2) == 'O')) //по вертикали 3-6-9
		{
			return Peek(2);
		}
		else return '-';
	}
};

template <typename T>
Stack<T>::Stack(int maxSize) : size(maxSize = 10)
{
	s = new T[maxSize];
	top = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] s;
}

template <typename T>
void Stack<T>::push(const T& value)
{
	s[top++] = value;
}

template <typename T>
T Stack<T>::pop()
{
	if (top > 0)
		return s[--top];
}

template <class T>
const T& Stack<T>::Peek(int nom) const
{
	if (nom <= top)
		return s[nom]; // вернуть n-й элемент стека
}


int main()
{
	setlocale(LC_ALL, "Rus");
	Stack <char> Stack(9);
	for (int i = 0; i < 9; i++)
	{
		Stack.push('-');
	}
	cout << "Введите имя игрока: ";
	cin >> Stack.PlayerName1;
	Stack.show_cells();
	for (int move = 1; move <= 9; move++)
	{
		if (move % 2) Stack.make_move(1);
		else
		{
			Stack.make_move(2);
		}
		Stack.show_cells();
		if (move >= 5)
			/*Если номер хода 5 или больше,  то проходит проверка на победу (раньше, чем на 5-ом ходе победить нельзя)*/
		{
			Stack.win = Stack.check(); //Символ победы - это возвращенное значение функции проверки
			if (Stack.win != '-') //Если символ победы не "-" (то есть кто-то победил),
				break; //то нет смысла в дальнейших ходах и цикл прерывается
		}
	}
	Stack.result();
	for (int i = 8; i >= 0; i--)
	{
		cout << Stack.Peek(i) << endl;
	}
	return 0;
}