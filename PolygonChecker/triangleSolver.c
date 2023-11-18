#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "triangleSolver.h"
#include "calculations.h"
#include "solveAngles.h"

#define MAXSTRING 100
#define MAXRESULT 300

char* analyzeTriangle(int side1, int side2, int side3) {

	// all three angles of triangle 
	double angleA = (double)side1;
	double angleB = (double)side2;
	double angleC = (double)side3;

	// turn angles from side lengths into actual angles 
	solveAngles(&angleA, &angleB, &angleC);

	// strings for displaying angles and type of triangle
	char result[MAXRESULT] = "";
	char angles[MAXSTRING] = "";
	char anglesactual[MAXSTRING] = "";

	// add all three angles to the angles actual string
	sprintf(angles, "%lg ", angleA);
	strcat(anglesactual, angles);
	sprintf(angles, "%lg ", angleB);
	strcat(anglesactual, angles);
	sprintf(angles, "%lg ", angleC);
	strcat(anglesactual, angles);

	
	// The following if structure determines the type of triangle and sets the value of result to the triangle type
	// with the three different angles, unless the shape is not a triangle

	// if all the angles do not add up to 180 then the shape is not a triangle, or if any angle is 0
	if (isTriangle(angleA, angleB, angleC) != true) {
		strcpy(result,"Not a triangle");
	}

	// if all three sides are the same then the triangle is equilateral 
	else if (side1 == side2 && side1 == side3) {
		strcpy(result,"Equilateral triangle with angles: ");
		strcat(result, anglesactual);
	}

	// if the triangle has a 90 degree angle then it is a right angle triangle
	else if (pythagTheorem(side1, side2, side3)) {
		
		strcpy(result, "Right triangle with angles: ");
		strcat(result, anglesactual);
	}

	// if 2 angles are the same and the other is different, the the triangle is isosceles
	else if ((angleA == angleB && angleA != angleC) || (angleC == angleB && angleC != angleA) || (angleA == angleC && angleA != angleB)) {
		strcpy(result, "Isosceles triangle with angles: ");
		strcat(result, anglesactual);
	}

	// in all other cases, the triangle is scalene
	else {
		strcpy(result, "Scalene triangle with angles: ");
		strcat(result, anglesactual);
	}

	// create a malloc with the value of result so that it can be returned properly 
	char* finalResult = (char*)malloc(strlen(result) + 1);
	strcpy(finalResult, result);

	return finalResult;
}

bool isTriangle(double angleA, double angleB, double angleC)
{

	// return false if any angle is 0, (triangle has 1 or more side lengths that are too long to form a triangle)
	if (angleA <= 0 || angleB <= 0 || angleC <= 0)
	{
		return false;
	}

	// calulate the sum of the three angles
	int sumOfAngles = angleA + angleB + angleC;

	// return true if sum of angles is 180 which indicates the shape is a triangle, other wise the shape is not and return false
	if (sumOfAngles != 180)
	{
		return false;
	}
	else
		return true;
}