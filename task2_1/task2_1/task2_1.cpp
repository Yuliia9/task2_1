
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct points
{
	float x;
	float y;
	float z;

};

/*sorted array of space points by ascending z coordinate */
void Sort_points(struct points *p, int n);

/*evaluate the distance between two points*/
double Get_distance(struct points *a, struct points *b);


int main(int argc, _TCHAR* argv[])
{
	unsigned int num;
	printf("Enter how many space points do you want to create: ");
	int retCode = scanf("%u", &num);
	if (retCode == 0)
	{
		printf("Type mismatch. Next time please enter integer number of points. \n");
		return 0;
	}
	
	struct points*  mas_of_points = (points*)malloc(num * sizeof(points));

	printf("Enter coordinates of space points in the form of x y z\n");
	int i;
	for (i = 0; i < num; i++)
	{
		printf("coordinate of %i space point:   ", i + 1);
		retCode = scanf("%f %f %f", &mas_of_points[i].x, &mas_of_points[i].y, &mas_of_points[i].z);
		if (retCode == 0)
		{
			printf("Type mismatch. Next time please enter decimal coordinate. \n");
			free(mas_of_points);
			return 0;
		}

	}

	printf(" \n Coordinate of points sorted by ascending z coordinate: \n");
	Sort_points(mas_of_points, num);
	for (i = 0; i < num; i++)
		printf("%i point: %.2f \t%.2f \t%.2f \n", i + 1, mas_of_points[i].x, mas_of_points[i].y, mas_of_points[i].z);

	double space = Get_distance(mas_of_points, mas_of_points + 1);
	int p1 = 0, p2 = 1;
	for (i = 0; i < num - 1; i++)
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


void Sort_points(struct points *p, int n)
{
	points a;
	for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n; j++)
	{
		if ((p + i)->z > (p + j)->z)
		{
			a = *(p + j);
			*(p + j) = *(p + i);
			*(p + i) = a;
		}
	}
}


double Get_distance(struct points *a, struct points *b)
{
	return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
}

