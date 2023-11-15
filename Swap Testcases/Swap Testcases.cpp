#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../PolygonChecker/rectangleSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SwapTestcases
{
	TEST_CLASS(SwapTestcases)
	{
	public:
		
		TEST_METHOD(SwapTest1)
		{
			int x1 = 4;
			int y1 = 5;
			int x2 = 2;
			int y2 = 1;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest2)
		{
			int x1 = 5;
			int y1 = 8;
			int x2 = 9;
			int y2 = 20;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest3)
		{
			int x1 = -2;
			int y1 = -7;
			int x2 = 2;
			int y2 = 7;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest4)
		{
			int x1 = 5;
			int y1 = 4;
			int x2 = -5;
			int y2 = -4;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest5)
		{
			int x1 = -10;
			int y1 = -8;
			int x2 = -4;
			int y2 = -3;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest6)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = 2;
			int y2 = 1;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest7)
		{
			int x1 = 5;
			int y1 = 23;
			int x2 = 0;
			int y2 = 0;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest8)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = 0;
			int y2 = 0;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest9)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = -20;
			int y2 = -10;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}

		TEST_METHOD(SwapTest10)
		{
			int x1 = -2;
			int y1 = -9;
			int x2 = 0;
			int y2 = 0;

			int x1temp = x1;
			int y1temp = y1;
			int x2temp = x2;
			int y2temp = y2;

			swap(&x1, &y1, &x2, &y2);

			Assert::AreEqual(x1, x2temp);
			Assert::AreEqual(y1, y2temp);
			Assert::AreEqual(x2, x1temp);
			Assert::AreEqual(y2, y1temp);
		}
	};
}
