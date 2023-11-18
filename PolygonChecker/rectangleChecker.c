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
	int highest = rectangleIndexes[1];
	int leftmost = rectangleIndexes[0];

	//get first point classified
	for (int i = 2; i < 8; i += 2)
	{
		//if 2 points are at the same highest point
		if (rectangleIndexes[i + 1] == highest)
		{
			if (rectangleIndexes[i] <= leftmost)
			{
				swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[i], &rectangleIndexes[i + 1]);
				highest = rectangleIndexes[1];
				leftmost = rectangleIndexes[0];
			}
		}
		//otherwise test if the point is higher
		else if (rectangleIndexes[i + 1] > highest)
		{
			swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[i], &rectangleIndexes[i + 1]);
			highest = rectangleIndexes[1];
			leftmost = rectangleIndexes[0];
		}
	}

	//second and fourth point classification
	//distance from point
	double dist1 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[2], rectangleIndexes[3]);
	double dist2 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[4], rectangleIndexes[5]);
	double dist3 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[6], rectangleIndexes[7]);

	//get hypotenuse to calculate angles
	double hyp1 = dist(rectangleIndexes[0] + dist1, rectangleIndexes[1], rectangleIndexes[2], rectangleIndexes[3]);
	double hyp2 = dist(rectangleIndexes[0] + dist2, rectangleIndexes[1], rectangleIndexes[4], rectangleIndexes[5]);
	double hyp3 = dist(rectangleIndexes[0] + dist3, rectangleIndexes[1], rectangleIndexes[6], rectangleIndexes[7]);

	//cosine law for angle calculations
	double angle1 = acos(((dist1 * dist1) + (dist1 * dist1) - (hyp1 * hyp1)) / (2 * dist1 * dist1));
	double angle2 = acos(((dist2 * dist2) + (dist2 * dist2) - (hyp2 * hyp2)) / (2 * dist2 * dist2));
	double angle3 = acos(((dist3 * dist3) + (dist3 * dist3) - (hyp3 * hyp3)) / (2 * dist3 * dist3));

	//convert to degrees
	double dAngle1 = angle1 * 180.0 / PI;
	double dAngle2 = angle2 * 180.0 / PI;
	double dAngle3 = angle3 * 180.0 / PI;

	if ((float)dAngle2 <= (float)dAngle1)
		if (dAngle2 < dAngle1)
			swap(&rectangleIndexes[2], &rectangleIndexes[3], &rectangleIndexes[4], &rectangleIndexes[5]);
		else if (dist2 < dist1)
			swap(&rectangleIndexes[2], &rectangleIndexes[3], &rectangleIndexes[4], &rectangleIndexes[5]);

	dist1 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[2], rectangleIndexes[3]);
	dist3 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[6], rectangleIndexes[7]);

	hyp1 = dist(rectangleIndexes[0] + dist1, rectangleIndexes[1], rectangleIndexes[2], rectangleIndexes[3]);
	hyp3 = dist(rectangleIndexes[0] + dist3, rectangleIndexes[1], rectangleIndexes[6], rectangleIndexes[7]);

	angle1 = acos(((dist1 * dist1) + (dist1 * dist1) - (hyp1 * hyp1)) / (2 * dist1 * dist1));
	angle3 = acos(((dist3 * dist3) + (dist3 * dist3) - (hyp3 * hyp3)) / (2 * dist3 * dist3));

	dAngle1 = angle1 * 180.0 / PI;
	dAngle3 = angle3 * 180.0 / PI;

	if ((float)dAngle3 <= (float)dAngle1)
		if (dAngle3 < dAngle1)
			swap(&rectangleIndexes[2], &rectangleIndexes[3], &rectangleIndexes[6], &rectangleIndexes[7]);
		else if (dist3 < dist1)
			swap(&rectangleIndexes[2], &rectangleIndexes[3], &rectangleIndexes[6], &rectangleIndexes[7]);

	dist2 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[4], rectangleIndexes[5]);
	dist3 = dist(rectangleIndexes[0], rectangleIndexes[1], rectangleIndexes[6], rectangleIndexes[7]);
	
	hyp2 = dist(rectangleIndexes[0] + dist2, rectangleIndexes[1], rectangleIndexes[4], rectangleIndexes[5]);
	hyp3 = dist(rectangleIndexes[0] + dist3, rectangleIndexes[1], rectangleIndexes[6], rectangleIndexes[7]);

	angle2 = acos(((dist2 * dist2) + (dist2 * dist2) - (hyp2 * hyp2)) / (2 * dist2 * dist2));
	angle3 = acos(((dist3 * dist3) + (dist3 * dist3) - (hyp3 * hyp3)) / (2 * dist3 * dist3));

	dAngle2 = angle2 * 180.0 / PI;
	dAngle3 = angle3 * 180.0 / PI;

	if ((float)dAngle3 <= (float)dAngle2)
		if (dAngle3 < dAngle2)
			swap(&rectangleIndexes[4], &rectangleIndexes[5], &rectangleIndexes[6], &rectangleIndexes[7]);
		else if (dist3 < dist2)
			swap(&rectangleIndexes[4], &rectangleIndexes[5], &rectangleIndexes[6], &rectangleIndexes[7]);
}

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
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
		double adjacent = rectangleVertexes[(i + 2) % 8] - rectangleVertexes[  i  ];	//adjacent is x values
		double opposite = rectangleVertexes[(i + 3) % 8] - rectangleVertexes[i + 1];	//opposite is y values

		//calculate side length using hypotenuse calculation
		double sidelength = sqrt(pow(adjacent, 2) + pow(opposite, 2));
		rectangleSides[i / 2] = sidelength;
	}

	//diagonals for cosine law calculation
	double diag1 = sqrt(pow(rectangleVertexes[4] - rectangleVertexes[0], 2) + pow(rectangleVertexes[5] - rectangleVertexes[1], 2));
	double diag2 = sqrt(pow(rectangleVertexes[2] - rectangleVertexes[6], 2) + pow(rectangleVertexes[3] - rectangleVertexes[7], 2));

	//set sides to easier to use variables
	double a = rectangleSides[0];
	double b = rectangleSides[1];
	double c = rectangleSides[2];
	double d = rectangleSides[3];

	//cosine law calculations to determine outside angles are 90
	float angle1 = acos(((a * a) + (b * b) - (diag1 * diag1)) / (2 * a * b));
	float angle2 = acos(((b * b) + (c * c) - (diag2 * diag2)) / (2 * b * c));
	float angle3 = acos(((c * c) + (d * d) - (diag1 * diag1)) / (2 * c * d));
	float angle4 = acos(((d * d) + (a * a) - (diag2 * diag2)) / (2 * d * a));

	//convert to degrees
	angle1 *= 180 / PI;
	angle2 *= 180 / PI;
	angle3 *= 180 / PI;
	angle4 *= 180 / PI;

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
	if (isRect)
		printf("These points make a rectangle with a perimeter of %lf and an area of %lf.\n", perimeter, area);
	else
		printf("These points do not make a rectangle. It has a perimeter of %lf.\n", perimeter);
}