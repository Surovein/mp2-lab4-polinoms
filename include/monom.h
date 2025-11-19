// класс или структура Монома (double коэффициент, целая свернутая степень)
using namespace std;
#include<stdint.h>
struct Monom
{
	double coeff;
	uint16_t degree;
	Monom(double c, uint16_t x)
	{
		coeff = c;
		degree = x;
	}
	bool operator<(Monom& m)
	{
		if (m.degree > degree)
		{
			return true;
		}
		return false;
	}
	bool operator==(Monom& m)
	{
		if (m.degree == degree)
		{
			return true;
		}
		return false;
	}
	Monom& operator=(Monom& mon)
	{
		degree = mon.degree;
		coeff = mon.coeff;
		return *this;
	}
};