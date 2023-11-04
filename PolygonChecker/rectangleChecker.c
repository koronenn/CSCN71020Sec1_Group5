#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "rectangleSolver.h"

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
				scanf("%*[^\n]");
			}
		} while (parsed != 1);
	}
	return rectangleIndexes;
}