//#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "../PolygonChecker/triangleSolver.c"
#include "../PolygonChecker/solveAngles.c"
#include "../PolygonChecker/calculations.c"
}

#define NOTTRIANGLE	"Not a triangle"
#define RIGHT		"Right triangle with angles:"
#define SCALENE		"Scalene triangle with angles:"
#define ISOSCELES	"Isosceles triangle with angles:"
#define EQUILATERAL "Equilateral triangle with angles:"

namespace analyzeTriangleTest
{
	TEST_CLASS(analyzeTriangleTest)
	{
	public:
		
		TEST_METHOD(RightTest1)
		{
			char* expected = RIGHT;

			int a = 3;
			int b = 4;
			int c = 5;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(RightTest2)
		{
			char* expected = RIGHT;

			int a = 5;
			int b = 12;
			int c = 13;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(RightTest3)
		{
			char* expected = RIGHT;

			int a = 7;
			int b = 24;
			int c = 25;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(RightTest4)
		{
			char* expected = RIGHT;

			int a = 20;
			int b = 21;
			int c = 29;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}


		TEST_METHOD(RightTest5)
		{
			char* expected = RIGHT;

			int a = 28;
			int b = 45;
			int c = 53;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(IsoscelesTest1)
		{
			char* expected = ISOSCELES;

			int a = 5;
			int b = 5;
			int c = 1;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(IsoscelesTest2)
		{
			char* expected = ISOSCELES;

			int a = 9;
			int b = 9;
			int c = 4;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(IsoscelesTest3)
		{
			char* expected = ISOSCELES;

			int a = 25;
			int b = 25;
			int c = 6;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(IsoscelesTest4)
		{
			char* expected = ISOSCELES;

			int a = 18;
			int b = 18;
			int c = 12;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(IsoscelesTest5)
		{
			char* expected = ISOSCELES;

			int a = 3;
			int b = 3;
			int c = 2;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(ScaleneTest1)
		{
			char* expected = SCALENE;

			int a = 2;
			int b = 3;
			int c = 4;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(ScaleneTest2)
		{
			char* expected = SCALENE;

			int a = 8;
			int b = 9;
			int c = 12;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(ScaleneTest3)
		{
			char* expected = SCALENE;

			int a = 5;
			int b = 7;
			int c = 9;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(ScaleneTest4)
		{
			char* expected = SCALENE;

			int a = 4;
			int b = 10;
			int c = 12;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(ScaleneTest5)
		{
			char* expected = SCALENE;

			int a = 3;
			int b = 5;
			int c = 7;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(EquilateralTest)
		{
			char* expected = EQUILATERAL;

			int a = 1;
			int b = 1;
			int c = 1;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(NotTriangleTest1)
		{
			char* expected = NOTTRIANGLE;

			int a = 1;
			int b = 10;
			int c = 1000;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(NotTriangleTest2)
		{
			char* expected = NOTTRIANGLE;

			int a = 5;
			int b = 10;
			int c = 15;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(NotTriangleTest3)
		{
			char* expected = NOTTRIANGLE;

			int a = -1;
			int b = 3;
			int c = 3;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(NotTriangleTest4)
		{
			char* expected = NOTTRIANGLE;

			int a = 'd';
			int b = 3;
			int c = 6;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}

		TEST_METHOD(NotTriangleTest5)
		{
			char* expected = NOTTRIANGLE;

			int a = 2;
			int b = 7;
			int c = 15;

			char* actual = analyzeTriangle(a, b, c);
			Assert::IsTrue(!strncmp(expected, actual, strlen(expected)));
		}
	};
}