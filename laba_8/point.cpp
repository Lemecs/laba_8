#include "point.h"
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void print_point(const POINT* p)
{
	printf("[%.2lf, %.2lf]\n", p->x, p->y);
}
double calculate_distance(const POINT* p1, const POINT* p2)
{
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}
int is_equal_points(const POINT* p1, const POINT* p2)
{
	return p1->x == p2->x && p1->y == p2->y;
}