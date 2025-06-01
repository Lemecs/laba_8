#include "circle_array.h"
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Circle_arraay {
	CIRCLE circles[MAX_SIZE];
	int top;
}ca;void fill_circle_array(int n, int dx, int dy, int dr)
{
	ca.top = 0;
	if (n > MAX_SIZE || n < 1)
	{
		fprintf(stderr, "Wrong number of circles\n");
		return;
	}
	for (; ca.top < n; ++ca.top)
	{
		ca.circles[ca.top].center.x = rand() % dx - dx / 2;
		ca.circles[ca.top].center.y = rand() % dy - dy / 2;
	}
}void print_circle_array()
{
	printf("Array of circles:\n");
	for (int i = 0; i < ca.top; ++i)
	{
		printf("Circle %d\n", i + 1);
		print_circle(&ca.circles[i]);
		printf("***********************\n");
	}
}void find_concentric()
{
	int flag = 0;
	for (int i = 0;i < ca.top;++i)
		for (int j = i + 1; j < ca.top; ++j)
		{
			if (is_concetric(&ca.circles[i], &ca.circles[j]))
			{
				printf("Circles %d and %d are concentric\n", i + 1, j + 1);
				flag = 1;
			}
		}
	if (!flag)
		printf("There are no concentric circles in array\n");
}