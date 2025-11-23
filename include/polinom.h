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
public:
	Polinom(): TSinglyList()
	{
	}

	Polinom(string& str): TSinglyList()
	{
		Parsing(str);
		Sort();
	}
	
	Polinom(Polinom& pol): TSinglyList(pol)
	{
	}

	void Parsing(string& str)
	{
		int index = 0;
		do
		{
			index = str.find_first_of("+-", index);
			Monom mon(str.substr(0, index));
			PushBack(mon);
			//PushBack(Monom(str.substr(0, index)));
			if (index != std::string::npos)
			{
				str.erase(0, index);
				index = 1;
			}
		}
		while (index != std::string::npos);

	}
	void Sort()
	{
		Polinom tmp;
		//Monom Bigest = this[0];
		for (int i = 0; i < sz; i++)
		{
			Monom Lowest = operator[](0);
			int index = -1;
			for (int j = 1; j < sz; i++)
			{
				if (operator[](j) < Lowest)
				{
					Lowest = operator[](j);
					index = j - 1;
				}
			}
			tmp.PushBack(Lowest);
			if (index == -1)
			{
				PopFront();
			}
			else
			{
				EraseAfter(index);
			}
		}
		operator=(tmp);
	}
	size_t size() const noexcept
	{
		return TSinglyList<Monom>::size();
	}
	Monom& operator[](size_t index)
	{
		return TSinglyList<Monom>::operator[](index);
	}
	Polinom& operator=(Polinom& pol) 
	{
		return (Polinom&) TSinglyList<Monom>::operator=(pol);
	}
	Polinom& operator*(double con)
	{
		for (int i = 0; i < size(); i++)
		{
			operator[](i) *= con;
		}
		return *this;
	}
	Polinom& operator*(Monom& mon)
	{
		for (int i = 0; i < size(); i++)
		{
			operator[](i) *= mon;
		}
		return *this;
	}
	Polinom& operator+(Polinom& pol)
	{
		for (int i = 0; i < size(); i++)
		{
			for (int j = 0; j < pol.size(); j++)
			{
				if (pol[j] == operator[](i))
				{
					operator[](i) += pol[j];
				}
				else if(j==pol.size()-1)
				{
					PushBack(pol[j]);
				}
			}
		}
		return *this;
	}
	Polinom& operator-(Polinom& pol)
	{
		for (int i = 0; i < size(); i++)
		{
			for (int j = 0; j < pol.size(); j++)
			{
				if (pol[j] == operator[](i))
				{
					operator[](i) -= pol[j];
				}
				else if (j == pol.size() - 1)
				{
					PushBack(pol[j]);
				}
			}
		}
		return *this;
	}
	void operator+=(Polinom& pol)
	{
		for (int i = 0; i < size(); i++)
		{
			for (int j = 0; j < pol.size(); j++)
			{
				if (pol[j] == operator[](i))
				{
					operator[](i) += pol[j];
				}
				else if (j == pol.size() - 1)
				{
					PushBack(pol[j]);
				}
			}
		}
	}
	void operator-=(Polinom& pol)
	{
		for (int i = 0; i < size(); i++)
		{
			for (int j = 0; j < pol.size(); j++)
			{
				if (pol[j] == operator[](i))
				{
					operator[](i) -= pol[j];
				}
				else if (j == pol.size() - 1)
				{
					PushBack(pol[j]);
				}
			}
		}
	}
	Polinom& operator*(Polinom& pol)
	{
		Monom tmp_mon;
		Polinom tmp;
		for (int i = 0; i < size(); i++)
		{
			for (int j = 0; j < pol.size(); j++)
			{
				tmp_mon = operator[](i) * pol[j];
				tmp.PushBack(tmp_mon);
				tmp_mon.Clear();
			}
		}
		tmp.Sort();
		return tmp;
	}
	~Polinom()
	{
		TSinglyList<Monom>::~TSinglyList();
	}
	bool operator==(Polinom& pol)
	{
		int k = 0;
		if (size() != pol.size())
		{
			return false;
		}
		else
		{
			for (int i = 0; i < size(); i++)
			{
				for (int j = 0; j < size(); j++)
				{
					if (operator[](i).compare(pol[j]))
					{
						k++;
					}
				}
				if (k == 0)
				{
					return false;
				}
			}
			k = 0;
			return true;
		}
	}
};