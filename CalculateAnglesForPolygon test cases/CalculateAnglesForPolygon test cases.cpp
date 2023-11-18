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
		
		TEST_METHOD(CalculateAnglesForPolygonTest1)
		{
			int rectangleVertices[] = {1,5,5,5,1,2,5,2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest2)
		{
			int rectangleVertices[] = {-1,2,5,2,5,1,-1,1};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest2Test1)
		{
			int rectangleVertices[] = { -1,5,5,5,5,1,-1,1 };
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest2Test2)
		{
			int rectangleVertices[] = { -1,3,5,3,5,1,-1,1 };
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest3)
		{
			int rectangleVertices[] = {5,-1,8,-1,8,-2,5,-2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest4)
		{
			int rectangleVertices[] = {-8,-1,-7,-1,-7,-2,-8,-2};
			double rectangleSidesPTR[4];

			Assert::IsTrue(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest5)
		{
			int rectangleVertices[] = {0,0,0,0,0,0,0,0};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest6)
		{
			int rectangleVertices[] = {1,2,3,4,5,6,7,8};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest7)
		{
			int rectangleVertices[] = {-3,5,7,5,5,4,-1,4};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}
		
		TEST_METHOD(CalculateAnglesForPolygonTest8)
		{
			int rectangleVertices[] = { -3,5,7,5,5,4,-1,4 };
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest9)
		{
			int rectangleVertices[] = {4,2,7,2,6,1,3,1};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}

		TEST_METHOD(CalculateAnglesForPolygonTest10)
		{
			int rectangleVertices[] = {1,3,2,3,1,2,3,2};
			double rectangleSidesPTR[4];

			Assert::IsFalse(CalculateAnglesForPolygon(rectangleVertices, rectangleSidesPTR));
		}
	};
}
