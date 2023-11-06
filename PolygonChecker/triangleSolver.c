#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "triangleSolver.h"
#include "calculations.h"
#include "solveAngles.h"

char* analyzeTriangle(int side1, int side2, int side3) {

	double angleA = (double)side1;
	double angleB = (double)side2;
	double angleC = (double)side3;

	solveAngles(&angleA, &angleB, &angleC);


	char result[300] = "";

	char angles[100] = "";
	char anglesactual[100] = "";

	sprintf(angles, "%lg ", angleA);
	strcat(anglesactual, angles);
	sprintf(angles, "%lg ", angleB);
	strcat(anglesactual, angles);
	sprintf(angles, "%lg ", angleC);
	strcat(anglesactual, angles);

	
	if (isTriangle(angleA, angleB, angleC) != true) {

		strcpy(result,"Not a triangle");

	}
	else if (side1 == side2 && side1 == side3) {
		strcpy(result,"Equilateral triangle with angles ");
		strcat(result, anglesactual);
	}
	else if (pythagTheorem(side1, side2, side3)) {
		
		strcpy(result, "Right triangle with angles ");
		strcat(result, anglesactual);
	}
	else if ((angleA == angleB && angleA != angleC) || (angleC == angleB && angleC != angleA) || (angleA == angleC && angleA != angleB)) {
		strcpy(result, "Isosceles triangle with angles ");
		strcat(result, anglesactual);
	}
	else {
		strcpy(result, "Scalene triangle with angles ");
		strcat(result, anglesactual);
	}

	char* finalResult = (char*)malloc(strlen(result) + 1);
	strcpy(finalResult, result);

	return finalResult;
}

bool isTriangle(double angleA, double angleB, double angleC)
{

	if (angleA == 0 || angleB == 0 || angleC == 0)
	{
		return false;
	}

	int sumOfAngles = angleA + angleB + angleC;

	if(sumOfAngles != 180)
	{
		return false;
	}
	else
	{
		return true;
	}
}