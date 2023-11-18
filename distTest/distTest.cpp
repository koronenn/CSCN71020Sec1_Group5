#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "../PolygonChecker/rectangleChecker.c"
}

namespace distTest
{
	TEST_CLASS(distTest)
	{
	public:
		
		TEST_METHOD(distTest1)
		{
			double x1 = 1;
			double y1 = 1;
			double x2 = 2;
			double y2 = 2;

			double expected = sqrt(2);
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest2)
		{
			double x1 = 1;
			double y1 = 1;
			double x2 = 1;
			double y2 = 1;

			double expected = 0;
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest3)
		{
			double x1 = -2;
			double y1 = 0;
			double x2 = 2;
			double y2 = 0;

			double expected = 4;
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest4)
		{
			double x1 = 3;
			double y1 = 5;
			double x2 = 1;
			double y2 = 2;

			double expected = sqrt(13);
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest5)
		{
			double x1 = 9;
			double y1 = -4;
			double x2 = -3;
			double y2 = 7;

			double expected = sqrt(265);
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest6)
		{
			double x1 = 1;
			double y1 = 1;
			double x2 = 2;
			double y2 = 1;

			double expected = 1;
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest7)
		{
			double x1 = -2;
			double y1 = -2;
			double x2 = -3;
			double y2 = -12;

			double expected = sqrt(101);
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(distTest8)
		{
			double x1 = -4;
			double y1 = -1;
			double x2 = 8;
			double y2 = 4;

			double expected = 13;
			double actual = dist(x1, y1, x2, y2);
			Assert::AreEqual(expected, actual);
		}
	};
}
