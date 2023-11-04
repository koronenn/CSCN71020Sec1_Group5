#define _CRT_SECRURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "rectangleSolver.h"

int* GetUserInput()
{
	int values[8] = { 0 };

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
			parsed = scanf_s("%d", &values[i]);
			if (parsed != 1)
			{
				fflush(stdin);
			}
		} while (parsed != 1);
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", values[i]);
	}
	return values;
}