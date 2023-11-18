#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../PolygonChecker/calculations.c"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pythagTheoremTestCases
{
	TEST_CLASS(pythagTheoremTestCases)
	{
	public:
		
		// Note: there really are no boundaries to test for this function, just right triangles
		// and non-right triangles / non-triangles

		// functional tests
		TEST_METHOD(pythagTheorem_Test1)
		{
			int sides[3] = { 13, 12, 5 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(pythagTheorem_Test2)
		{
			int sides[3] = { 3, 5, 4 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(pythagTheorem_Test3)
		{
			int sides[3] = { 20, 21, 29 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(pythagTheorem_Test4)
		{
			int sides[3] = { 7, 25, 24 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(pythagTheorem_Test5)
		{
			int sides[3] = { 53, 45, 28 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsTrue(actual);
		}
		TEST_METHOD(pythagTheorem_Test6)
		{
			int sides[3] = { 12, 35, 37 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsTrue(actual);
		}

		// exception tests

		TEST_METHOD(pythagTheorem_Test7)
		{
			int sides[3] = { 5, 5, 5 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test8)
		{
			int sides[3] = { 12, 12, 6 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test9)
		{
			int sides[3] = { 8, 4, 8 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test10)
		{
			int sides[3] = { 3, 4, 4 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test11)
		{
			int sides[3] = { 4, 5, 25 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test12)
		{
			int sides[3] = { 50, 2, 3 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test13)
		{
			int sides[3] = { 10, 100, 1 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test14)
		{
			int sides[3] = { 3, 5, 7 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
		TEST_METHOD(pythagTheorem_Test15)
		{
			int sides[3] = { 9, 8, 4 };

			bool actual = pythagTheorem(sides[0], sides[1], sides[2]);
			Assert::IsFalse(actual);
		}
	};
}
