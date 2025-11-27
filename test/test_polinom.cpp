// тесты мономов и полиномов
#include <gtest.h>
#include "list.h"
#include <vector>
#include"polinom.h"
using namespace std;
TEST(vector, test1)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	for (int i = 0; i < v.size(); i++)
	{
		EXPECT_EQ(list[i], v[i]);
	}
}
TEST(copy, test2)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	TSinglyList<int> tmp(list);
	for (int i = 0; i < v.size(); i++)
	{
		EXPECT_EQ(tmp[i], list[i]);
	}
}
TEST(copy, test3)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	TSinglyList<int> tmp;
	tmp = list;
	for (int i = 0; i < v.size(); i++)
	{
		EXPECT_EQ(tmp[i], list[i]);
	}
}
TEST(clear, test4)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	list.Clean();
	EXPECT_EQ(true, list.IsEmpty());
}
TEST(popfront, test5)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	list.PopFront();
	EXPECT_EQ(2, list[0]);
}
TEST(popfront, test6)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	list.PopFront();
	EXPECT_EQ(4, list.size());
}
TEST(PushAfter, test7)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	list.PushAfter(0, 10);
	EXPECT_EQ(list[1], 10);
}
TEST(PushAfter, test8)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	list.PushAfter(0, 10);
	EXPECT_EQ(list.size(), 6);
}
TEST(PushAfter, test9)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	ASSERT_ANY_THROW(list.PushAfter(-1, 10));
}
TEST(PushAfter, test10)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	TSinglyList<int> list(v);
	ASSERT_ANY_THROW(list.PushAfter(20, 10));
}
TEST(PushAfter, test11)
{
	vector<int> v = { 1 };
	TSinglyList<int> list(v);
	list.PushAfter(0, 10);
	EXPECT_EQ(list[1], 10);
}
TEST(PushAfter, test12)
{
	vector<int> v = { 1,2 };
	TSinglyList<int> list(v);
	list.PushAfter(1, 10);
	EXPECT_EQ(list[2], 10);
}
TEST(EraseAfter, test13)
{
	vector<int> v = { 1,2,3,4,5 };
	TSinglyList<int> list(v);
	list.EraseAfter(1);
	EXPECT_EQ(list[2], 4);
}
TEST(EraseAfter, test14)
{
	vector<int> v = { 1,2,3,4,5 };
	TSinglyList<int> list(v);
	list.EraseAfter(1);
	EXPECT_EQ(list.size(), 4);
}
TEST(EraseAfter, test15)
{
	vector<int> v = { 1,2,3,4,5 };
	TSinglyList<int> list(v);
	ASSERT_ANY_THROW(list.EraseAfter(-1));
}
TEST(EraseAfter, test16)
{
	vector<int> v = { 1,2,3,4,5 };
	TSinglyList<int> list(v);
	ASSERT_ANY_THROW(list.EraseAfter(-1));
}
TEST(EraseAfter, test17)
{
	vector<int> v = { 1,2,3,4,5 };
	TSinglyList<int> list(v);
	list.EraseAfter(3);
	EXPECT_EQ(list.LastValue(), 4);
}
TEST(Polinom_stroka, test18)
{
	string tmp = "5x0y2z1+3x5y1z1";
	Polinom pol(tmp);
	vector<Monom> v = { {3,511},{5,21} };
	for (int i = 0; i < pol.size(); i++)
	{
		EXPECT_EQ(pol[i].compare(v[i]),true);
	}
}

TEST(Polinom_polinom, test100)
{
	string tmp = "0";
	Polinom pol(tmp);
	Polinom Pol(pol);
	EXPECT_EQ(pol == Pol, true);
}

TEST(Polinom_polinom, test101)
{
	string tmp = "0";
	string tmp2 = "5x0y2z1";
	Polinom pol1(tmp);
	Polinom pol2(tmp2);
	Polinom Pol(tmp2);
	Polinom res = pol1 + pol2;
	EXPECT_EQ(true,Pol == res);
}

TEST(Polinom_polinom, test102)
{
	string tmp = "0";
	string tmp2 = "5x0y2z1";
	Polinom pol1(tmp);
	Polinom pol2(tmp2);
	Polinom Pol(tmp);
	Polinom res = pol2 - pol2;
	EXPECT_EQ(true,Pol == res);
}


TEST(Polinom_polinom, test19)
{
	string tmp = "5x0y2z1+3x5y1z1";
	Polinom pol(tmp);
	Polinom Pol(pol);
	EXPECT_EQ(pol == Pol, true);
}
TEST(Polinom_const, test20)
{
	string tmp1 = "5x0y2z1+3x5y1z1";
	string tmp2 = "50x0y2z1+30x5y1z1";
	Polinom pol(tmp1);
	Polinom res(tmp2);
	double c = 10;
	EXPECT_EQ(pol*10 == res, true);
}
TEST(Polinom_monom, test21)
{
	string tmp1 = "5x0y2z1+3x5y1z1";
	string tmp2 = "50x2y4z3+30x7y3z3";
	Polinom pol(tmp1);
	Polinom res(tmp2);
	Monom m(10,222);
	EXPECT_EQ(pol * m == res, true);
}
TEST(Polinom_polinom, test22)
{
	string tmp1 = "5x0y2z1+3x5y1z1";
	string tmp3 = "5x0y2z1+3x5y1z1";
	string tmp4 = "5x0y2z1+3x5y1z1";
	string tmp2 = "9x5y1z1+15x0y2z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom pol2(tmp4);
	Polinom res(tmp2);
	Polinom RES = pol + pol1 + pol2;
	//for (int i = 0; i < RES.size(); i++)
	//{
	//	cout << RES[i] << endl;
	//}
	//cout << "-------" << endl;
	EXPECT_EQ(RES == res, true);
}
TEST(Polinom_polinom, test23)
{
	string tmp1 = "5x0y2z1+3x5y1z1";
	string tmp3 = "10x1y2z1+10x2y1z1";
	string tmp4 = "5x0y2z1+3x5y1z1";
	string tmp2 = "10x0y2z1+6x5y1z1+10x1y2z1+10x2y1z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom pol2(tmp4);
	Polinom res(tmp2);
	Polinom RES;
	RES = pol + pol1 + pol2;
	//for (int i = 0; i < RES.size(); i++)
	//{
	//	cout << RES[i] << endl;
	//}
	//EXPECT_EQ(RES == res, true);
}
TEST(Polinom_polinom, test24)
{
	string tmp1 = "5x0y2z1+3x5y1z1";
	string tmp3 = "5x0y2z1+3x5y1z1";
	string tmp2 = "0x0y2z1+0x5y1z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	RES = pol - pol1;
	EXPECT_EQ(RES == res, true);
}
TEST(Polinom_polinom, test25)
{
	string tmp1 = "5x0y2z1+3x5y1z1";
	string tmp3 = "5x0y2z1+3x5y1z1-4x2y2z1";
	string tmp2 = "0x0y2z1+0x5y1z1+4x2y2z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	RES = pol - pol1;
	EXPECT_EQ(RES == res, true);
}
TEST(Polinom_polinom, test26)
{
	string tmp1 = "-5x0y2z1+3x5y1z1";
	string tmp3 = "-5x0y2z1+3x5y1z1-4x2y2z1";
	string tmp2 = "0x0y2z1+0x5y1z1+4x2y2z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	RES = pol - pol1;
	EXPECT_EQ(RES == res, true);
}
TEST(Polinom_polinom, test261)
{
	string tmp1 = "-5x0y2z1+3x5y1z1";
	string tmp3 = "-5x0y2z1+3x5y1z1";
	string tmp2 = "0";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	RES = pol - pol1;
	EXPECT_EQ(RES == res, true);
}
TEST(Polinom_polinom, test27)
{
	string tmp1 = "-5x0y2z1+3x5y1z1";
	string tmp3 = "-5x0y2z1+3x5y1z1-4x2y2z1";
	string tmp2 = "-10x0y2z1+6x5y1z1-4x2y2z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	pol+=pol1;
	EXPECT_EQ(pol == res, true);
}
TEST(Polinom_polinom, test28)
{
	string tmp1 = "-5x0y2z1+3x5y1z1";
	string tmp3 = "-5x0y2z1+3x5y1z1-4x2y2z1";
	string tmp2 = "0x0y2z1+0x5y1z1+4x2y2z1";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	pol -= pol1;
	EXPECT_EQ(pol == res, true);
}
TEST(Polinom_polinom, test29)
{
	string tmp1 = "-5x0y2z1";
	string tmp3 = "-5x0y2z1+3x2y1z1";
	string tmp2 = "25x0y4z2-15x2y3z2";
	Polinom pol(tmp1);
	Polinom pol1(tmp3);
	Polinom res(tmp2);
	Polinom RES;
	RES = pol1*pol;
	//for (int i = 0; i < RES.size(); i++)
	//{
	//	cout <<"RES[i]=="<< RES[i] << endl;
	//}
	EXPECT_EQ(RES == res, true);
}