#include "pch.h"
#include "CppUnitTest.h"

#define SQUARE_SIDES 4

extern "C" 
{
#include "../PolygonChecker/rectangleChecker.c"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GetPerimeterUnitTests

	// this funcntion has no boundaries or excpetions to test, only functional tests
{
	TEST_CLASS(GetPerimeterUnitTests)
	{
	public:
		
		TEST_METHOD(GetPerimeter_Test1)
		{
			double sides[SQUARE_SIDES] = {3,3,3,3};
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, 12.0);
			
		}
		TEST_METHOD(GetPerimeter_Test2)
		{
			double sides[SQUARE_SIDES] = { -2,-3,8.5,1.5 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, 5.0);

		}
		TEST_METHOD(GetPerimeter_Test3)
		{
			double sides[SQUARE_SIDES] = { 0,0,0,2 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, 2.0);

		}
		TEST_METHOD(GetPerimeter_Test4)
		{
			double sides[SQUARE_SIDES] = { 0,0,-4.75,0 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, -4.75);

		}
		TEST_METHOD(GetPerimeter_Test5)
		{
			double sides[SQUARE_SIDES] = { 0,-0.03,0,0 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, -0.03);

		}
		TEST_METHOD(GetPerimeter_Test6)
		{
			double sides[SQUARE_SIDES] = { 4.9,0,0,0 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, 4.9);

		}
		TEST_METHOD(GetPerimeter_Test7)
		{
			double sides[SQUARE_SIDES] = { 0,0,0,0 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual(actual, 0.0);

		}
		TEST_METHOD(GetPerimeter_Test8)
		{
			double sides[SQUARE_SIDES] = { 4.5, -4.5, 3.2, -3.0 };
			double actual = GetPerimeter(sides);

			Assert::AreEqual((float)actual, (float)0.2);

		}
	};
}
