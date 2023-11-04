#pragma once

#include <stdbool.h>

/*
* This function returns the largest of three integers passed in
* 
* int: first num to check
* int: second num to check
* int: third num to check 
* 
* return: the largest of the three
*/
int getLargest(int, int, int);

/*
* This function calculates Pythagoras theorem given three side lengths
* and determines whether or not the triangle passed in is a right angle
* 
* int: first side length
* int: second side length
* int: third side length
* 
* return: true if the triangle passed in is right angle, otherwise false
*         (i.e. true if Pythagoras theorem is equal to hypotenuse)
*/
bool pythagTheorem(int, int, int);