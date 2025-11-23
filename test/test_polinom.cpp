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