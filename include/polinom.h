// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов
using namespace std;
#include "list.h"
#include "monom.h"
#include<string>
#include<stdint.h>
class Polinom : private TSinglyList<Monom>
{
	Polinom()
	{
		pFirst = nullptr;
		pEnd = nullptr;
		sz = 0;
	}
	Polinom(string& str)
	{

	}
	Polinom(Polinom& pol)
	{

	}
	void Parsing(string& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			Monom tmp();
			if (str[i] != '+' || str[i] != '-')
			{

			}
		}
	}
	void Sort()
	{

	}
	Polinom& operator=(Polinom& pol)
	{

	}
	Polinom& operator*(double con)
	{

	}
	Polinom& operator*(Monom& mon)
	{

	}
	Polinom& operator+(Polinom& pol)
	{

	}
	Polinom& operator-(Polinom& pol)
	{

	}
	void operator+=(Polinom& pol)
	{

	}
	void operator-=(Polinom& pol)
	{

	}
	Polinom& operator*(Polinom& pol)
	{

	}
	~Polinom()
	{

	}
};