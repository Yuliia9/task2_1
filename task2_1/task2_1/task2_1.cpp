
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "task2_1.h"

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCESS = 0;

/*the number of coordinates in point (number of fields in struct point)*/
const int LEN = 3;

//#define UNITTEST



#ifdef UNITTEST

int main()
{
	Test();
}
#else
int main()
{
	Interface();
	unsigned int num;
	unsigned char retCode;
	do
	{
		printf("Enter integer number of space points that you want to create: ");
		retCode = scanf("%u", &num);
		fflush(stdin); // Flush the input buffer
	}while (Type_checking(retCode, (int) num) == ERROR);
		

	struct point*  points = (point*)malloc(num * sizeof(point));
	if (points == NULL)
	{
		printf("Error occurs while trying to allocate memory for list of points. \n");
		return (int)ERROR;
	}

	printf("Enter coordinates of space points separated by comma \n (in the form of x,y,z): \n");

	retCode = Input(points, num);
	if (retCode == ERROR)
	{
		return (int)ERROR;
	}


	printf(" \n Coordinate of points sorted by ascending z coordinate: \n");
	retCode = Sort_points(points, num);
	if (retCode == ERROR)
	{
		printf("The problem occur while trying to sort points.\n");
		return (int)ERROR;
	}

	retCode = Output(points, num);
	if (retCode == ERROR)
	{
		printf("The problem occur while trying to display points.\n");
		return (int)ERROR;
	}

	retCode = Display_distance(points, num);
	if (retCode == ERROR)
	{
		printf("The problem occur while trying to display smallest distance.\n");
		return (int)ERROR;
	}
	
	free(points);
	system("pause");
	return (int)MAIN_SUCCESS;
}
#endif
void Interface()
{
	printf("Hi! Introduce to your attention a program that creates for you ");
	printf("\n a desire length list of space points,");
	printf("\n sorts the points by ascending z coordinate ");
	printf("\nand estimates for you the smallest distance between points;)\n");
	printf("Program made by Yuliia Lyubchik.\n");
}

unsigned char Type_checking(int retCode, int val)
{
	if (retCode == ERROR)
	{
		printf("Type mismatch. Please next time check if you enter integer number. \n");
		return ERROR;
	}
	if (val <= 0)
	{
		printf("The value can not be negative or null.\n");
		return ERROR;
	}
	return SUCCESS;
}

unsigned char Input(struct point* points, unsigned int num)
{
	if (points == NULL)
	{
		return ERROR;
	}

	char temp[20];
	char* token;
	unsigned int i, coord_count = 0;
	float temp_num[LEN];
	for (i = 0; i < num; ++i)
	{
		printf("coordinate of %i space point:   ", i + 1);
		scanf("%s", &temp);
		token = strtok(temp, ",");

		while (token != NULL && coord_count < LEN)
		{
			if (Is_digit(token) == ERROR)
			{
				printf("Type mismatch. Next time please check if you entered three float or integer numbers \n");
				fflush(stdin);
				break;
			}
			temp_num[coord_count] = atof(token);
			printf("%f",temp_num[coord_count]);
			token = strtok(NULL, ",");
			coord_count++;
		}
		if (coord_count != LEN)
		{
			printf("Coordinates wasn't inputed . \n");
			--i;
			continue;
		}
		points[i].x = temp_num[0];
		points[i].y = temp_num[1];
		points[i].z = temp_num[2];
	}
	return SUCCESS;
}


unsigned char Is_digit(const char* pstr)
{
	unsigned int i;
	unsigned char krapka = 0;
	for (i = 0; i < strlen(pstr); ++i)
	{
		if (i == 0)
		{
			if (pstr[i] == '-')
			{
				continue;
			}
		}
		if (pstr[i] >= 48 && pstr[i] <= 57)
		{
			continue;
		}
		else if (pstr[i] == '.')
		{
			if (krapka == 0)
			{
				krapka = 1;
			}
			else
			{
				return ERROR;
			}
		}
		else return ERROR;
	}
	return SUCCESS;
}

unsigned char Output(const struct point* points, unsigned int num)
{
	if (points == NULL)
	{
		return ERROR;
	}
	unsigned int i;
	for (i = 0; i < num; i++)
		printf("%i point: %f \t%f \t%f \n", i + 1, points[i].x, points[i].y, points[i].z);
	return SUCCESS;
}

unsigned char Sort_points(struct point *p, unsigned int num)
{
	if (p == NULL)
	{
		return ERROR;
	}
	struct point temp;
	unsigned int i, j;
	for (i = 0; i < num; i++)
	for (j = i + 1; j < num; j++)
	{
		if ((p + i)->z >(p + j)->z)
		{
			memcpy(&temp, p + j, sizeof(point));
			memcpy(p + j, p + i, sizeof(point));
			memcpy(p + i, &temp, sizeof(point));
		}
	}
	return SUCCESS;
}
unsigned char Display_distance(const struct point* p, unsigned int num)
{
	if (p == NULL)
	{
		return ERROR;
	}
	if (num == 1)
	{
		printf("Not enough  point to estimate the smallest distance\n");
		return SUCCESS;
	}
	unsigned int i, j;
	double space = 0;
	int p1 = 0, p2 = 1;
	for (i = 0; i < num - 1; ++i )
	{

		for (j = i + 1; j < num; ++j )
		{
			double temp = Get_distance(p + i, p + j);
			if (space > temp)
			{
				space = temp;
				p1 = i; p2 = j;

			}
		}
	}
	printf("The smallest distance is between %i point and %i point.  \n", p1 + 1, p2 + 1);
	return SUCCESS;
}


double Get_distance(const struct point *a, const struct point *b)
{
	if (a == NULL || b == NULL)
	{
		printf("Error occur while getting distance between points. \n");
		return ERROR;
	}
	double x = (a->x - b->x) * (a->x - b->x);
	double y = (a->y - b->y) * (a->y - b->y);
	double z = (a->z - b->z) * (a->z - b->z);
	return sqrt(x + y + z);
}

void Test()
{
	unsigned char retCode;
	char* values[] = { "a", "1.2", "-1.3", "5-6", "0..5", "8p", "8.8.8", "q9" };
	
	for (unsigned int i = 0; i < 8; ++i)
	{
		printf("for %s ", values[i]);
		if (Is_digit(values[i]) == ERROR)
		{
			printf("Test failed\n");
		}
		else
		{
			printf("Test passed\n");
		}
	}
}









