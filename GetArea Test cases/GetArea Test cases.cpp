#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../PolygonChecker/rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GetAreaTestcases
{
	TEST_CLASS(GetAreaTestcases)
	{
	public:
		
		TEST_METHOD(GETAREA1)
		{
			double expected = 10;
			double sides[] = {2, 5};

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA2)
		{
			double expected = 0.88;
			double sides[] = { 0.22, 4 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA3)
		{
			double expected = 0.66;
			double sides[] = { 2, 0.33 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA4)
		{
			double expected = 0.495;
			double sides[] = { 1.5, 0.33 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA5)
		{
			double expected = 0;
			double sides[] = { 21, 0 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA6)
		{
			double expected = 0;
			double sides[] = { 0, 9 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA7)
		{
			double expected = 0;
			double sides[] = { 0, 0 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA8)
		{
			double expected = -3;
			double sides[] = { 2, -1.5 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA9)
		{
			double expected = -9;
			double sides[] = { -3, 3 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GETAREA10)
		{
			double expected = 20;
			double sides[] = { -5, -4 };

			double actual = GetArea(sides);

			Assert::AreEqual(expected, actual);
		}
	};
}
