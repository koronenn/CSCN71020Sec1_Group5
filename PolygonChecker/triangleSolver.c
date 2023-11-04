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

    char result[100] = "";

    char angles[100];
    char anglesactual[100] = "";

    sprintf(angles, "%lf ", angleA);
    strcat(anglesactual, angles);
    sprintf(angles, "%lf ", angleB);
    strcat(anglesactual, angles);
    sprintf(angles, "%lf ", angleC);
    strcat(anglesactual, angles);

    //printf(anglesactual);

    if (isTriangle(angleA, angleB, angleC) != true) {
        strncpy(result,"Not a triangle", 100);
    }
    else if (side1 == side2 && side1 == side3) {
        strncpy(result, "Equilateral triangle with sides: ", 100);
        strcat(result, anglesactual);
    }
    else if (pythagTheorem(side1, side2, side3)) {
        strncpy(result, "Right angle triangle with sides: ", 100);
        strcat(result, anglesactual);
    }
    else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
        strncpy(result, "Isocelese triangle with sides: ", 100);
        strcat(result, anglesactual);
    }
    else {
        strncpy(result, "Scalene triangle with sides: ", 100);
        strcat(result, anglesactual);
    }


    // for debugging
    // printf("%s\n",result);

    // I think the problem here is result get destroyed after the function ends which is why there is an access writing violation if
    // you try to return he pointer to the array, because result no longer exists, so i think we have to use malloc in order
    // to return the result
    return strncpy((char*)malloc(100 * sizeof(char)),result,100);
}

bool isTriangle(double angleA, double angleB, double angleC)
{
    int sumOfAngles = angleA + angleB + angleC;

    //printf("%")
    //printf("%d", sumOfAngles);
    if (angleA == 0 || angleB == 0 || angleC == 0)
    {
        return false;
    }
    if (sumOfAngles != 180)
    {
        return false;
    }
    else
    {
        return true;
    }
}