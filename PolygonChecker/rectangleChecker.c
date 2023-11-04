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
				scanf_s("%*[^\n]");
			}
		} while (parsed != 1);
	}
	printf("Inputted\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", rectangleIndexes[i]);
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
			//determine point 1 (top most always, leftmost if 2 points or more at same max Y)
			if (rectangleIndexes[1] < rectangleIndexes[(y + 2) % 8])
			{
				if (rectangleIndexes[0] >= rectangleIndexes[(y + 1) % 8])
				{
					//swap point X with first index
					swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[(y + 1) % 8], &rectangleIndexes[(y + 2) % 8]);
					printf("Found");
				}
			}

			//determine point 2(rightmost always, uppermost if 2 or more points at same X)
			if (rectangleIndexes[x] <= rectangleIndexes[(x + 2) % 8])
			{
				if (rectangleIndexes[(x + 1) % 8] < rectangleIndexes[(x + 3) % 8])
				{
					swap(&rectangleIndexes[x], &rectangleIndexes[x+1], &rectangleIndexes[(x + 2) % 8], &rectangleIndexes[(x + 3) % 8]);
				}
			}

			//point 3: lowest, rightmost
			if (rectangleIndexes[y] > rectangleIndexes[(y + 2) % 8])
			{
				if (rectangleIndexes[(y - 1) % 8] <= rectangleIndexes[(y - 3) % 8])
				{
					swap(&rectangleIndexes[x], &rectangleIndexes[x + 1], &rectangleIndexes[(x + 2) % 8], &rectangleIndexes[(x + 3) % 8]);
				}
			}

			//point 4: left, lowest
			if (rectangleIndexes[x] <= rectangleIndexes[(x + 2) % 8])
			{
				if (rectangleIndexes[(x + 1) % 8] < rectangleIndexes[(x + 3) % 8])
				{
					swap(&rectangleIndexes[x], &rectangleIndexes[x + 1], &rectangleIndexes[(x + 2) % 8], &rectangleIndexes[(x + 3) % 8]);
				}
			}
		}
	}
	printf("Adjusted\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", rectangleIndexes[i]);
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