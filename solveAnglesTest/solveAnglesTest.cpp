#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C"
{
#include "../PolygonChecker/solveAngles.c"
}

//https://www.calculatorsoup.com/calculators/geometry-plane/triangle-law-of-cosines.php

namespace solveAnglesTest
{
	TEST_CLASS(solveAnglesTest)
	{
	public:

		TEST_METHOD(RightTriangle1)
		{
			double a = 3;
			double b = 4;
			double c = 5;

			float expectedA = 36.869897;
			float expectedB = 53.130103;
			float expectedC = 90;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(RightTriangle2)
		{
			double a = 1;
			double b = 1;
			double c = sqrt(2);

			float expectedA = 45;
			float expectedB = 45;
			float expectedC = 90;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(RightTriangle3)
		{
			double a = 5;
			double b = 12;
			double c = 13;

			float expectedA = 22.619865;
			float expectedB = 67.380135;
			float expectedC = 90.0;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(RightTriangle4)
		{
			double a = 7;
			double b = 24;
			double c = 25;

			float expectedA = 16.260204;
			float expectedB = 73.739795;
			float expectedC = 90.0;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(RightTriangle5)
		{
			double a = 20;
			double b = 21;
			double c = 29;

			float expectedA = 43.602819;
			float expectedB = 46.397181;
			float expectedC = 90.0;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(IcoscelesTest1)
		{
			double a = 5;
			double b = 5;
			double c = 1;

			float expectedA = 84.260829;
			float expectedB = 84.260829;
			float expectedC = 11.478341;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(IcoscelesTest2)
		{
			double a = 7;
			double b = 7;
			double c = 12;

			float expectedA = 31.002719;
			float expectedB = 31.002719;
			float expectedC = 117.994562;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}
		TEST_METHOD(IcoscelesTest3)
		{
			double a = 9;
			double b = 9;
			double c = 4;

			float expectedA = 77.160411;
			float expectedB = 77.160411;
			float expectedC = 25.679176;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}
		TEST_METHOD(IcoscelesTest4)
		{
			double a = 100;
			double b = 100;
			double c = 25;

			float expectedA = 82.819244;
			float expectedB = 82.819244;
			float expectedC = 14.361511;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}
		TEST_METHOD(IcoscelesTest5)
		{
			double a = 25;
			double b = 25;
			double c = 40;

			float expectedA = 36.869897;
			float expectedB = 36.869897;
			float expectedC = 106.260205;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(ScaleneTest1)
		{
			double a = 3;
			double b = 6;
			double c = 8;

			float expectedA = 18.573349;
			float expectedB = 39.571219;
			float expectedC = 121.855431;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(ScaleneTest2)
		{
			double a = 9;
			double b = 12;
			double c = 14;

			float expectedA = 39.571219;
			float expectedB = 58.144569;
			float expectedC = 82.284211;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(ScaleneTest3)
		{
			double a = 2;
			double b = 3;
			double c = 4;

			float expectedA = 28.955024;
			float expectedB = 46.567463;
			float expectedC = 104.477512;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(ScaleneTest4)
		{
			double a = 7;
			double b = 9;
			double c = 10;

			float expectedA = 42.833428;
			float expectedB = 60.940718;
			float expectedC = 76.225853;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(ScaleneTest5)
		{
			double a = 100;
			double b = 120;
			double c = 153;

			float expectedA = 40.770997;
			float expectedB = 51.595513;
			float expectedC = 87.633489;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(EquilateralTest)
		{
			double a = 1;
			double b = 1;
			double c = 1;

			float expectedA = 60;
			float expectedB = 60;
			float expectedC = 60;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(NotTriangleTest1)
		{
			double a = 1;
			double b = 10;
			double c = 1000;

			float expectedA = 0;
			float expectedB = 0;
			float expectedC = 180;

			solveAngles(&a, &b, &c);

			Assert::AreNotEqual(expectedA, (float)a);
			Assert::AreNotEqual(expectedB, (float)b);
			Assert::AreNotEqual(expectedC, (float)c);
		}

		TEST_METHOD(NotTriangleTest2)
		{
			double a = 1;
			double b = 2;
			double c = 3;

			float expectedA = 0;
			float expectedB = 0;
			float expectedC = 180;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}

		TEST_METHOD(NotTriangleTest3)
		{
			double a = -10;
			double b = 8;
			double c = 10;

			float expectedA = 0;
			float expectedB = 0;
			float expectedC = 180;

			solveAngles(&a, &b, &c);

			Assert::AreNotEqual(expectedA, (float)a);
			Assert::AreNotEqual(expectedB, (float)b);
			Assert::AreNotEqual(expectedC, (float)c);
		}

		TEST_METHOD(NotTriangleTest4)
		{
			double a = 5;
			double b = 'c';
			double c = 5;

			float expectedA = 0;
			float expectedB = 0;
			float expectedC = 0;

			solveAngles(&a, &b, &c);

			Assert::AreNotEqual(expectedA, (float)a);
			Assert::AreNotEqual(expectedB, (float)b);
			Assert::AreNotEqual(expectedC, (float)c);
		}

		TEST_METHOD(NotTriangleTest5)
		{
			double a = 1;
			double b = 1;
			double c = 2;

			float expectedA = 0;
			float expectedB = 0;
			float expectedC = 180;

			solveAngles(&a, &b, &c);

			Assert::AreEqual(expectedA, (float)a);
			Assert::AreEqual(expectedB, (float)b);
			Assert::AreEqual(expectedC, (float)c);
		}
	};
}