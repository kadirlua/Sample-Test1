#include "pch.h"
#include "myClass.h"

namespace myClassTest {

	myClass::myClass(int x) noexcept : 
		mx{ x }
	{
	}

	myClass::myClass(std::string str) noexcept : 
		mstr{ std::move(str) }
	{
	}

	myClass::myClass(int x, std::string str) noexcept : 
		mx{ x }, 
		mstr{ std::move(str) }
	{
	}

	void myClass::addSum(int a) noexcept
	{
		mx += a;
	}

	void myClass::appendStr(std::string str) noexcept
	{
		mstr += str;
	}
}