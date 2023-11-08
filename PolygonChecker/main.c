#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);

			// deallocate result
			free(result);
			break;
		case 2:
			printf("Rectangle Selected.\n");
			int rectangleVertexes[8] = { 0 };
			int* rectangleVertexesPtr = GetRectangleIndexes(rectangleVertexes);
			ClassifyPoints(rectangleVertexesPtr);
			double* rectangleSidesPtr[4] = {0};
			bool isRect;
			if (isRect = CalculateAnglesForPolygon(rectangleVertexesPtr, rectangleSidesPtr))
			{
				double perimeter = GetPerimeter(rectangleSidesPtr);
				double area = GetArea(rectangleSidesPtr);
				PrintRectangle(isRect, perimeter, area);
			}
			else
			{
				double perimeter = GetPerimeter(rectangleSidesPtr);
				PrintRectangle(isRect, perimeter, 0.0);
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			scanf_s("%*[^\n]");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%d", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		while (scanf("%d", &triangleSides[i]) != 1)
		{
			printf("invalid input, please Enter the three sides of the triangle: ");
			scanf_s("%*[^\n]");
		}
	}
	return triangleSides;
}