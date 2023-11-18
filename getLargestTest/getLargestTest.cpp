#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "../PolygonChecker/calculations.c"
}

namespace getLargestTest
{
	TEST_CLASS(getLargestTest)
	{
	public:
		
		TEST_METHOD(GetLargest1)
		{
			int a = 3;
			int b = 4;
			int c = 5;

			int expected = 5;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest2)
		{
			int a = 5;
			int b = 13;
			int c = 12;

			int expected = 13;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest3)
		{
			int a = 28;
			int b = 20;
			int c = 21;

			int expected = 28;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest4)
		{
			int a = 43;
			int b = 34;
			int c = 21;

			int expected = 43;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest5)
		{
			int a = 25;
			int b = 20;
			int c = 40;

			int expected = 40;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest6)
		{
			int a = 17;
			int b = 18;
			int c = 16;

			int expected = 18;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest7)
		{
			int a = 18;
			int b = 18;
			int c = 16;

			int expected = 18;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest8)
		{
			int a = 7;
			int b = 4;
			int c = 7;

			int expected = 7;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest9)
		{
			int a = 1;
			int b = 3;
			int c = 3;

			int expected = 3;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest10)
		{
			int a = 5;
			int b = 2;
			int c = 2;

			int expected = 5;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest11)
		{
			int a = 1;
			int b = 6;
			int c = 1;

			int expected = 6;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest12)
		{
			int a = 7;
			int b = 7;
			int c = 9;

			int expected = 9;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest13)
		{
			int a = 7;
			int b = 4;
			int c = -9;

			int expected = 7;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest14)
		{
			int a = 5;
			int b = -12;
			int c = 4;

			int expected = 5;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetLargest15)
		{
			int a = 12;
			int b = 0;
			int c = -6;

			int expected = 12;
			int actual = getLargest(a, b, c);

			Assert::AreEqual(expected, actual);
		}
	};
}

/*int a = ;
int b = ;
int c = ;

int expected = ;
int actual = getLargest(a, b, c);

Assert::AreEqual(expected, actual);*/