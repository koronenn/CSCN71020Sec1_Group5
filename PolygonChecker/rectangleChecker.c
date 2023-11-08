#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"
#include "solveAngles.h"

#define PI 3.14159265358979323846

int* GetRectangleIndexes(int* rectangleIndexes)
{
	for (int i = 0; i < 8; i++)
	{
		int parsed;
		do {
			//repeatedly asks user for input until they enter a valid option
			if (i % 2 == 0)
				printf("Enter X value %d: ", (i / 2 + 1));
			else
				printf("Enter Y value %d: ", (i / 2 + 1));

			//determine if input is int, otherwise clear the input buffer
			parsed = scanf_s("%d", &rectangleIndexes[i]);
			if (parsed != 1)
			{
				printf("Not valid input, try again.\n");
				scanf_s("%*[^\n]");
			}
		} while (parsed != 1);
	}
	return rectangleIndexes;
}

//function will determine which index the point is and
//reorder the points in the array accordingly
void ClassifyPoints(int* rectangleIndexes)
{
	//even numbers signify X values in rectangle indexes
	// odd numbers signify Y values in rectangle indexes
	for (int x = 0; x < 8; x += 2)
	{
		for (int y = 1; y < 8; y += 2)
		{
			//check point 1: highest, leftmost
			if (rectangleIndexes[1] <= rectangleIndexes[y] && rectangleIndexes[0] >= rectangleIndexes[y - 1])
			{
				swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[y-1], &rectangleIndexes[y]);
			}

			//check point 2: rightmost, highest
			if (rectangleIndexes[2] <= rectangleIndexes[x] && rectangleIndexes[3] >= rectangleIndexes[x + 1])
			{
				swap(&rectangleIndexes[2], &rectangleIndexes[3], &rectangleIndexes[x], &rectangleIndexes[x + 1]);
			}

			//check point 3: lowest, rightmost
			if (rectangleIndexes[5] >= rectangleIndexes[y] && rectangleIndexes[4] <= rectangleIndexes[y - 1])
			{
				swap(&rectangleIndexes[4], &rectangleIndexes[5], &rectangleIndexes[y - 1], &rectangleIndexes[y]);
			}

			//check point 4: leftmost, lowest
			if (rectangleIndexes[6] >= rectangleIndexes[x] && rectangleIndexes[7] >= rectangleIndexes[x + 1])
			{
				swap(&rectangleIndexes[6], &rectangleIndexes[7], &rectangleIndexes[x], &rectangleIndexes[x + 1]);
			}
		}
	}
}

void swap(int* x1, int* y1, int* x2, int* y2)
{
	//swap the points 
	int temp = *(x1);
	*(x1) = *(x2);
	*(x2) = temp;

	temp = *(y1);
	*(y1) = *(y2);
	*(y2) = temp;
}

bool CalculateAnglesForPolygon(int* rectangleVertexes, double* rectangleSides)
{
	bool isRectangle = true;
	for (int i = 0; i < 8; i += 2)
	{
		int adjacent = rectangleVertexes[(i + 2) % 8] - rectangleVertexes[  i  ];	//adjacent is x values
		int opposite = rectangleVertexes[(i + 3) % 8] - rectangleVertexes[i + 1];	//opposite is y values

		//calculate side length using hypotenuse calculation
		double sidelength = sqrt(pow(adjacent, 2) + pow(opposite, 2));
		rectangleSides[i / 2] = sidelength;
	}

	//diagonals for cosine law calculation
	double diag1 = sqrt(pow(rectangleSides[0], 2) + pow(rectangleSides[1], 2));
	double diag2 = sqrt(pow(rectangleSides[2], 2) + pow(rectangleSides[1], 2));

	//set sides to easier to use variables
	double a = rectangleSides[0];
	double b = rectangleSides[1];
	double c = rectangleSides[2];
	double d = rectangleSides[3];

	//cosine law calculations to determine outside angles are 90
	double angle1 = acos(((a * a) + (b * b) - (diag1 * diag1)) / (2 * a * b));
	double angle2 = acos(((b * b) + (c * c) - (diag2 * diag2)) / (2 * b * c));
	double angle3 = acos(((c * c) + (d * d) - (diag1 * diag1)) / (2 * c * d));
	double angle4 = acos(((d * d) + (a * a) - (diag2 * diag2)) / (2 * d * a));

	//convert to degrees and deal with floating point arithmetic errors
	angle1 *= 180 / PI;
	angle2 *= 180 / PI;
	angle3 *= 180 / PI;
	angle4 *= 180 / PI;

	//round to 6 decimals
	angle1 *= 1000000;
	angle2 *= 1000000;
	angle3 *= 1000000;
	angle4 *= 1000000;

	//convert to int to truncate
	angle1 = (int)angle1;
	angle2 = (int)angle2;
	angle3 = (int)angle3;
	angle4 = (int)angle4;

	//convert back to double
	angle1 /= 1000000;
	angle2 /= 1000000;
	angle3 /= 1000000;
	angle4 /= 1000000;

	if (angle1 == 90 && angle2 == 90 && angle3 == 90 && angle4 == 90)
		return true;
	return false;
}

double GetPerimeter(double* sides)
{
	//loop through sides and add them to the perimeter
	double perimeter = 0;
	for (int i = 0; i < 4; i++)
	{
		perimeter += sides[i];
	}
	return perimeter;
}

double GetArea(double* sides)
{
	double area;
	area = sides[0] * sides[1];
	return area;
}

void PrintRectangle(bool isRect, double perimeter, double area)
{
	if(isRect)
		printf("These points make a rectangle with perimeter %lf and area %lf.\n", perimeter, area);
	else
		printf("These points do not make a rectangle with perimeter %lf.\n", perimeter);
}