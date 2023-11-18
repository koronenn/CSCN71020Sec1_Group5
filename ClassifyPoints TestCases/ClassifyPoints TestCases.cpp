#include "pch.h"
#include "CppUnitTest.h"

#define AMOUNT_OF_POINTS 8 

extern "C"
{
#include "../PolygonChecker/rectangleChecker.c"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ClassifyPointsTestCases
{
	TEST_CLASS(ClassifyPointsTestCases)
	{
	public:

		// 4! = 24, meaning there are 24 ways the different points can be inputted
		// which means there should be at least 24 test cases minimum

		// the following are each possible scenario the points can be input in and cover each one

		// The function

		/******
		* 1234 *
		* 1243 *
		* 1423 *
		* 1432 *
		* 1324 *
		* 1342 *
		* 2134 *
		* 2143 *
		* 2341 *
		* 2314 *
		* 2413 *
		* 2431 *
		* 3124 *
		* 3142 *
		* 3214 *
		* 3241 *
		* 3412 *
		* 3421 *
		* 4123 *
		* 4132 *
		* 4213 *
		* 4231 *
		* 4312 *
		* 4321 *
		 ******/

		 // this function has no boundaries or exceptions to test, only functional tests

		 // basic square
		TEST_METHOD(ClassifyPoints_Test1)
		{
			int points[] = { 2,1, 2,2, 1,2, 1,1 };
			int pointsInOrder[]{ 1,2, 2,2, 2,1, 1,1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Side ways rectangle
		TEST_METHOD(ClassifyPoints_Test2)
		{
			int points[] = { 4,-1, 1,2, -1,0, 2,-3 };
			int pointsInOrder[] = { 1,2, 4,-1, 2,-3, -1,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next three tests use points that create a rectangle that spans all 4 quadrants in the
		// quartesian plane 
		TEST_METHOD(ClassifyPoints_Test3)
		{
			int points[] = { 2,1, -1,1, 2, -1, -1,-1 };
			int pointsInOrder[] = { -1,1, 2,1, 2,-1, -1,-1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test4)
		{
			int points[] = { 2,1, 2,-1, -1,1, -1,-1 };
			int pointsInOrder[] = { -1,1, 2,1, 2,-1, -1,-1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test5)
		{
			int points[] = { 2,1, -1,-1, 2, -1, -1,1 };
			int pointsInOrder[] = { -1,1, 2,1, 2,-1, -1,-1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next three tests use points that create a square in the shape of a diamond
		TEST_METHOD(ClassifyPoints_Test6)
		{
			int points[] = { 1,0, 0,1, 0,-1, -1,0 };
			int pointsInOrder[] = { 0,1, 1,0, 0,-1, -1,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		TEST_METHOD(ClassifyPoints_Test7)
		{
			int points[] = { 0,-1, 0,1, -1,0, 1,0 };
			int pointsInOrder[] = { 0,1, 1,0, 0,-1, -1,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(pointsInOrder[i], points[i]);
			}

		}

		TEST_METHOD(ClassifyPoints_Test8)
		{
			int points[] = { -1,0, 0,1, 0,-1, 1,0 };
			int pointsInOrder[] = { 0,1, 1,0, 0,-1, -1,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next three tests use points that create another sideways rectangle
		TEST_METHOD(ClassifyPoints_Test9)
		{
			int points[] = { 5,1, 2,2, 2,4, 5,3 };
			int pointsInOrder[] = { 2,4, 5,3, 5,1, 2,2 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test10)
		{
			int points[] = { 2,2, 5,3, 2,4, 5,1 };
			int pointsInOrder[] = { 2,4, 5,3, 5,1, 2,2 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test11)
		{
			int points[] = { 2,4, 2,2, 5,3, 5,1 };
			int pointsInOrder[] = { 2,4, 5,3, 5,1, 2,2 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next three tests use points that create a long vertical triangle rectangle
		TEST_METHOD(ClassifyPoints_Test12)
		{
			int points[] = { 0,-4, 0,0, 1,0, 1,-4 };
			int pointsInOrder[] = { 0,0, 1,0, 1,-4, 0,-4 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test13)
		{
			int points[] = { 0,0, 1,-4, 0,-4, 1,0 };
			int pointsInOrder[] = { 0,0, 1,0, 1,-4, 0,-4 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test14)
		{
			int points[] = { 0,-4, 0,0, 1,0, 1,-4 };
			int pointsInOrder[] = { 0,0, 1,0, 1,-4, 0,-4 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next four tests use points that create a long horizontal triangle rectangle
		TEST_METHOD(ClassifyPoints_Test15)
		{
			int points[] = { 0,1, 6,1, 6,0, 0,0 };
			int pointsInOrder[] = { 0,1, 6,1, 6,0, 0,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test16)
		{
			int points[] = { 6,0, 0,0, 6,1, 0,1 };
			int pointsInOrder[] = { 0,1, 6,1, 6,0, 0,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test17)
		{
			int points[] = { 6,0, 6,1, 0,0, 0,1 };
			int pointsInOrder[] = { 0,1, 6,1, 6,0, 0,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test18)
		{
			int points[] = { 0,0, 6,0, 6,1, 0,1 };
			int pointsInOrder[] = { 0,1, 6,1, 6,0, 0,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next three tests use points that create a 2x2 square in the 4th quadrant 
		TEST_METHOD(ClassifyPoints_Test19)
		{
			int points[] = { -3,-3, -1,-1, -1,-3, -3,-1 };
			int pointsInOrder[] = { -3,-1, -1,-1, -1,-3, -3,-3 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test20)
		{
			int points[] = { -3,-1, -1,-3, -1,-1, -3,-3 };
			int pointsInOrder[] = { -3,-1, -1,-1, -1,-3, -3,-3 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test21)
		{
			int points[] = { -3,-1, -3,-3, -1,-3, -1,-1 };
			int pointsInOrder[] = { -3,-1, -1,-1, -1,-3, -3,-3 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Next three tests use points that create a basic rectangle
		TEST_METHOD(ClassifyPoints_Test22)
		{
			int points[] = { 1,4, 4,4, 1,1, 4,1 };
			int pointsInOrder[] = { 1,4, 4,4, 4,1, 1,1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test23)
		{
			int points[] = { 4,4, 4,1, 1,1, 1,4 };
			int pointsInOrder[] = { 1,4, 4,4, 4,1, 1,1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}
		TEST_METHOD(ClassifyPoints_Test24)
		{
			int points[] = { 1,1, 4,1, 1,4, 4,4, };
			int pointsInOrder[] = { 1,4, 4,4, 4,1, 1,1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// These are not rectangles, but should still be ordered starting from the top most point
		// top left if there are two

		// Random, boomerang like shape
		TEST_METHOD(ClassifyPoints_Test25)
		{
			int points[] = { 0,-2, 2,-7, -1,2, 3,14 };
			int pointsInOrder[] = { 3,14, 2,-7, 0,-2, -1,2 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Parallelogram
		TEST_METHOD(ClassifyPoints_Test26)
		{
			int points[] = { 4,4, 1,1, 3,1, 2,4 };
			int pointsInOrder[] = { 2,4, 4,4, 3,1, 1,1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// Another shape with random plotted points  
		TEST_METHOD(ClassifyPoints_Test27)
		{
			int points[] = { 3,-16, 0,2, -4,-1, -5,17 };
			int pointsInOrder[] = { -5, 17, 0,2, 3,-16, -4,-1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// this is a line
		TEST_METHOD(ClassifyPoints_Test28)
		{
			int points[] = { 4,1, 7,1, 2,1, 5,1 };
			int pointsInOrder[] = { 2,1, 4,1, 5,1, 7,1 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// this is a trapezoid
		TEST_METHOD(ClassifyPoints_Test29)
		{
			int points[] = { 6,2, 2,2, 3,4, 5,4 };
			int pointsInOrder[] = { 3,4, 5,4, 6,2, 2,2 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

		// sideways triangle
		TEST_METHOD(ClassifyPoints_Test30)
		{
			int points[] = { 2,2, -3,-3, -2,0, -1,-1 };
			int pointsInOrder[] = { 2,2, -1,-1, -3,-3, -2,0 };

			ClassifyPoints(points);

			for (int i = 0; i < AMOUNT_OF_POINTS; i++) {
				Assert::AreEqual(points[i], pointsInOrder[i]);
			}
		}

	};
}
