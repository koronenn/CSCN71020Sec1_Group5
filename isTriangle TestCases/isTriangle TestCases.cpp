#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../PolygonChecker/triangleSolver.c"
#include "../PolygonChecker/calculations.c"
#include "../PolygonChecker/solveAngles.c"
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isTriangleTestCases
{
	TEST_CLASS(isTriangleTestCases)
	{
	public:
		
		// functional tests
		TEST_METHOD(isTriangle_Test1)
		{
			double angles[3] = { 90, 45, 45 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test2)
		{
			double angles[3] = { 67.34, 32.86, 79.80 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test3)
		{
			double angles[3] = { 30, 60, 90 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test4)
		{
			double angles[3] = { 56, 12, 112 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test5)
		{
			double angles[3] = { 160, 5, 15 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}

		// exception tests
		TEST_METHOD(isTriangle_Test6)
		{
			double angles[3] = { 30, 60, 30 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(isTriangle_Test7)
		{
			double angles[3] = { 90, 180, -90 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(isTriangle_Test8)
		{
			double angles[3] = { 0, 90, 90 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(isTriangle_Test9)
		{
			double angles[3] = { 90, 0, 90 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(isTriangle_Test10)
		{
			double angles[3] = { 90, 90, 0 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}

		// boundary tests 
		TEST_METHOD(isTriangle_Test11)
		{
			double angles[3] = { 59.9999, 60, 60 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(isTriangle_Test12)
		{
			double angles[3] = { 0.0001, 90, 89.9999 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test13)
		{
			double angles[3] = { 90, 0.0001, 89.9999 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test14)
		{
			double angles[3] = { 90, 89.9999, 0.0001 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(isTriangle_Test15)
		{
			double angles[3] = { -0.01, 90, 90.01 };

			bool actual = isTriangle(angles[0], angles[1], angles[2]);
			Assert::IsFalse(actual);
		}
	};
}
