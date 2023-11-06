#include "calculations.h"

// returns largest of passed in variables
int getLargest(int a, int b, int c) {

	// return a if its larger then both b and c
	if (a > b && a > c) 
		return a;

	// return b if larger c
	else if (b > c) 
		return b;

	// otherwise return c
	else 
		return c;

}

// calculate pythag theorem with three given side lengths
bool pythagTheorem(int side1, int side2, int side3) {

	// variables 
	int hyp = getLargest(side1, side2, side3);
	double pythag;


	// calculate Pythagoras theorem based on what side is the hypotenuse
	if (hyp == side1)
		pythag = sqrt((side3 * side3) + (side2 * side2));
	else if (hyp == side2)
		pythag = sqrt((side3 * side3) + (side1 * side1));
	else
		pythag = sqrt((side1 * side1) + (side2 * side2));

	// return true/false based on whether the hypotenuse is equal to Pythagoras theorem  calculation
	
	if (hyp == pythag)
		return true;
	else
		return false;

}