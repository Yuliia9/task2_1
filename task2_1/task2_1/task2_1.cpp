
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct points
{
	int x;
	int y;
	int z;

};

/*checking entered data and return 0 if type doesn't match requirements*/
int Type_checking(int retCode, int val);

/*input coordinates of space points into list of points return 0 if some data doesn't match requirements*/
int Input(struct points* mas_of_points, int num);

/*checking if string pstr involves only digits*/
int Is_digit(char* pstr);

/*sorted array of space points by ascending z coordinate */
void Sort_points(struct points *p, int n);

/*evaluate the distance between two points*/
double Get_distance(struct points *a, struct points *b);


int main( )
{
	int num;
	printf("Enter integer number of space points that you want to create: ");
	int retCode = scanf("%i", &num);

	if (0 == Type_checking(retCode, num))
	{
		return 0;
	}
	
	struct points*  mas_of_points = (points*)malloc(num * sizeof(points));

	printf("Enter integer coordinates of space points separated by comma \n (in the form of x,y,z): \n");
	retCode = Input(mas_of_points, num);
	if (0 == retCode)
	{
		return 0;
	}
	

	printf(" \n Coordinate of points sorted by ascending z coordinate: \n");
	Sort_points(mas_of_points, num);
	for (int i = 0; i < num; i++)
		printf("%i point: %i \t%i \t%i \n", i + 1, mas_of_points[i].x, mas_of_points[i].y, mas_of_points[i].z);

	double space = Get_distance(mas_of_points, mas_of_points + 1);
	int p1 = 0, p2 = 1;
	for (int i = 0; i < num - 1; i++)
	{

		for (int j = i + 1; j<num; j++)
		{
			if (space > Get_distance(mas_of_points + i, mas_of_points + j))
			{
				space = Get_distance(mas_of_points + i, mas_of_points + j);
				p1 = i; p2 = j;

			}
		}
	}
	printf("The smallest distance is between %i point and %i point.  \n", p1 + 1, p2 + 1);
	free(mas_of_points);
	return 0;
}

int Type_checking(int retCode, int val)
{
	if (0 == retCode)
	{
		printf("Type mismatch. Please next time check if you enter integer number. \n");
		return 0;
	}
	if (val < 0)
	{
		printf("The value can not be negative or null.\n");
		return 0;
	}
	return 1;
}

int Input(struct points* mas_of_points, int num)
{
	char temp[20];
	char* token;
	for (int i = 0; i < num; i++)
	{
		printf("coordinate of %i space point:   ", i + 1);
		scanf("%s", &temp);

		int coord_count = 0;
		int temp_num[3];
		token = strtok(temp, ",");

		while (token != NULL && coord_count < 3)
		{
			if (0 == Is_digit(token))
			{
				printf("Type mismatch. Next time please check if you entered number \n");
				return 0;
			}
			temp_num[coord_count] = atoi(token);
			token = strtok(NULL, ",");
			coord_count++;
		}
		if (coord_count != num)
		{
			printf("Warning! Not all coordinates inputed . \n");
		}
		mas_of_points[i].x = temp_num[0];
		mas_of_points[i].y = temp_num[1];
		mas_of_points[i].z = temp_num[2];

		
	}
	return 1;
}

int Is_digit(char* pstr)
{
	char* psubstr;
	char key[] = "0123456789";
	psubstr = strpbrk(pstr, key);
	if (psubstr == NULL)
	{
		return 0;
	}
	int shift = 0;
	while (psubstr != NULL)
	{
		if (psubstr != (pstr + shift))
		{
			return 0;
		}
		psubstr = strpbrk(psubstr + 1, key);
		shift++;
	}
	return 1;
}

void Sort_points(struct points *p, int num)
{
	points temp;
	for (int i = 0; i < num; i++)
	for (int j = i + 1; j < num; j++)
	{
		if ((p + i)->z > (p + j)->z)
		{
			temp = *(p + j);
			*(p + j) = *(p + i);
			*(p + i) = temp;
		}
	}
}


double Get_distance(struct points *a, struct points *b)
{
	return sqrt((double)(a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
}




	
	

	