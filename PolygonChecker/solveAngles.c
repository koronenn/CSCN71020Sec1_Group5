#include <math.h>
#include <stdio.h>
#include "triangleSolver.h"

#define PI 3.14159265358979323846

void solveAngles(double* side1, double* side2, double* side3) {

    // these variables are turned into doubles so that the cosine law calculates correctly 
    double a = *side1;
    double b = *side2;
    double c = *side3;

    //// Solving formula for cosine law to get angle c
    // c^2 = a^2 + b^2 - 2ab cos(c)
    // a^2 + b^2 = c^2 + 2ab cos(c)
    // a^2 + b^2 - c^2 = 2ab cos(c)
    // (a^2 + b^2 - c^2) / 2ab = cos c
    // cos^-1((a^2 + b^2 - c^2) / 2ab) = c*

    double angle1 = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
    // convert to degrees
    angle1 = (angle1 * 180) / PI;

    double angle2 = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c));
    // convert to degrees
    angle2 = (angle2 * 180) / PI;

    double angle3 = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b));
    // convert to degrees
    angle3 = (angle3 * 180) / PI;

	if (isTriangle(angle1, angle2, angle3)) {
		printf("Angle 1 %.2lf", angle1);
		printf("Angle 2 %.2lf", angle2);
		printf("Angle 3 %.2lf", angle3);
	}
	else {
		printf("The side lengths do not create a triangle");
	}
}