#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "../PolygonChecker/rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculateAnglesForPolygontestcases
{
	TEST_CLASS(CalculateAnglesForPolygontestcases)
	{
	public:
		
		TEST_METHOD(TestingForNormalRectangle1)
		{
			//test case testing for a normal rectangle 
			int rectangleVertices[] = {1,5,5,5,5,2,1,2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForNormalRectangle2)
		{
			//test case testing for a rectangle with a width of 1
			int rectangleVertices[] = {-1,2,5,2,5,1,-1,1};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForNormalRectangleInNegativeYAxis)
		{
			//test case testing for a rectangle with a width of 1 in the negative y-axis
			int rectangleVertices[] = {5,-1,8,-1,8,-2,5,-2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForNormalRectangleInNegativeXAndYAxis)
		{
			//testing for a rectangle in the negative x and y axis
			int rectangleVertices[] = {-8,-1,-7,-1,-7,-2,-8,-2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForOnlyZerosInputted)
		{
			//test case testing for when only 0's are inputted into the array
			int rectangleVertices[] = {0,0,0,0,0,0,0,0};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalLine)
		{
			//test ase testing for when inputs make a diagonal line
			int rectangleVertices[] = {1,2,3,4,5,6,7,8};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalLine2)
		{
			//test ase testing for when inputs make a diagonal line on the negative y-Axis
			int rectangleVertices[] = { 1,-2,3,-4,5,-6,7,-8 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalLine3)
		{
			//test ase testing for when inputs make a diagonal line on the negative x and y axis
			int rectangleVertices[] = { -1,-2,-3,-4,-5,-6,-7,-8};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalLine4)
		{
			//test ase testing for when inputs make a diagonal line in the negative x-axis
			int rectangleVertices[] = { -1,2,-3,4,-5,6,-7,8 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingforAbnormalShape1)
		{
			//test case testing a non-rectangle shape in the negative x and y axis
			int rectangleVertices[] = { -2,-4,-3,-7,-5,-9,-7,-10};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingforAbnormalShape2)
		{
			//test case testing an abnormal shape in the positive x and y axis
			int rectangleVertices[] = { 2,4,3,7,5,9,7,10 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingforAbnormalShape3)
		{
			//test case testing an abnormal shape in the negative x-axis
			int rectangleVertices[] = { -2,4,-3,7,-5,9,-7,10 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingforAbnormalShape4)
		{
			//test case testing an abnormal shape in the negative y axis
			int rectangleVertices[] = { 2,-4,3,-7,5,-9,7,-10 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingforAbnormalShape5)
		{
			//test case testing a trapezoid
			int rectangleVertices[] = {-3,5,7,5,5,4,-1,4};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForParallelogram)
		{
			//test case testing for a parallelogram
			int rectangleVertices[] = {4,2,7,2,6,1,3,1};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForTrapezoid)
		{
			//test case testing for another trapezoid
			int rectangleVertices[] = {1,3,2,3,1,2,3,2};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalRectangle1)
		{
			//test case testing for a diagonal rectangle with an upwards slope
			int rectangleVertices[] = { 1,5,5,7,6,5,2,3 };
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalRectangle2)
		{
			//test case testing for a diagonal rectangle with a downwards slope
			int rectangleVertices[] = {	1,5,5,3,4,1,0,3};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForDiagonalRectangle3)
		{
			//test case testing for a diagonal rectangle in the negative x-axis with an upwards slope
			int rectangleVertices[] = { -2,4,0,3,-1,1,-3,2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForSidewaysRectangle1)
		{
			//test case testing for a sideways rectangle in the positive x and y axis
			int rectangleVertices[] = { 1,5,4,5,4,0,1,0};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForSidewaysRectangle2)
		{
			//test case testing for a sideways rectangle in the negative y-axis
			int rectangleVertices[] = { 1,-5,4,-5,4,0,1,0 };
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForSidewaysRectangle3)
		{
			//test case testing for a sideways rectangle in the negative x-axis
			int rectangleVertices[] = { -1,5,-4,5,-4,0,-1,0 };
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForSidewaysRectangle4)
		{
			//test case testing for a sideways rectangle in the negative x and y axis
			int rectangleVertices[] = { -1,-5,-4,-5,-4,0,-1,0 };
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForStraightLine1)
		{
			//test case testing for a straight line in the positive x and y axis
			int rectangleVertices[] = { 1,2,3,2,5,2,9,2 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForStraightLine2)
		{
			//test case testing for a sideways rectangle in the negative x-axis
			int rectangleVertices[] = { -1,2,-3,2,-5,2,-9,2 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForStraightLine3)
		{
			//test case testing for a sideways rectangle in the negative x and y axis
			int rectangleVertices[] = { -1,-2,-3,-2,-5,-2,-9,-2 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(TestingForStraightLine4)
		{
			//test case testing for a sideways rectangle in the negative y axis
			int rectangleVertices[] = { 1,-2,3,-2,5,-2,9,-2 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}
	};
}
