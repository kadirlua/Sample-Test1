#include "pch.h"
#include "myClass.h"

int Func(int a = 5)
{
	return a * a;
}

int Foo(int a, int b)
{
	if (b < 0)
		throw std::exception("Some exception occours here!");
	return a * b;
}

TEST(MyFirstTest, DummyTest) {
	myClassTest::myClass m1{15};
	m1.addSum(10);
	EXPECT_EQ(m1.getVal(), 25);
	myClassTest::myClass m2{ "Test Case" };
	m2.appendStr(" 1");
	EXPECT_EQ(m2.getStr(), "Test Case 1");

	EXPECT_DOUBLE_EQ(m1.getVal(), 25.3);

	EXPECT_FALSE(m1.getVal() > 0);
}

TEST(MySecondTest, DummyTest2) {
	using namespace myClassTest;

	myClass m1{ 15, "Test" }, m2{ 10, "Test" };

	ASSERT_TRUE(m1 == m2);

	m2.addSum(5);

	EXPECT_TRUE(m1 == m2);
}

TEST(FinalTest, FuncTest)
{
	ASSERT_EQ(Func(2), 4);

	ASSERT_THROW(Foo(2, -4), std::exception);

	ASSERT_THROW(Foo(2, -4), std::runtime_error);
}

TEST(assert_throw_succeeds)
{
	std::vector<int> v;
	EXPECT_THROW((void)v.at(3), std::out_of_range);
}

TEST(assert_throw_fails)
{
	std::vector<int> v;
	ASSERT_THROW((void)v.at(3), std::domain_error);
}