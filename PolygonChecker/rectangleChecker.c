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
			//check point 1: highest, leftmost
			if (rectangleIndexes[1] <= rectangleIndexes[y])
			{
				if (rectangleIndexes[0] > rectangleIndexes[y-1])
				{
					swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[y-1], &rectangleIndexes[y]);
				}
			}

			//check point 2: rightmost, highest
			if (rectangleIndexes[2] <= rectangleIndexes[x])
			{
				if (rectangleIndexes[3] > rectangleIndexes[x + 1])
				{
					//swap(&rectangleIndexes[2], &rectangleIndexes[3], &rectangleIndexes[x], &rectangleIndexes[x+1]);

					swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[y - 1], &rectangleIndexes[y]);
				}
			}

			//check point 3: lowest, rightmost
			if (rectangleIndexes[5] >= rectangleIndexes[y])
			{
				if (rectangleIndexes[4] < rectangleIndexes[y - 1])
				{
					//swap(&rectangleIndexes[4], &rectangleIndexes[5], &rectangleIndexes[y - 1], &rectangleIndexes[y]);

					swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[y - 1], &rectangleIndexes[y]);
				}
			}

			//check point 4: leftmost, lowest
			if (rectangleIndexes[6] >= rectangleIndexes[y])
			{
				if (rectangleIndexes[7] > rectangleIndexes[y - 1])
				{
					//swap(&rectangleIndexes[6], &rectangleIndexes[7], &rectangleIndexes[x], &rectangleIndexes[x+1]);

					swap(&rectangleIndexes[0], &rectangleIndexes[1], &rectangleIndexes[y - 1], &rectangleIndexes[y]);
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