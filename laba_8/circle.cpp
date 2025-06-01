#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include "ñircle.h"
#include <stdio.h>

void print_circle(const CIRCLE* c)
{
	printf("Center ");
	print_point(&c->center);
	printf("Radius is %.2lf\n", c->radius);
}
int is_concetric(const CIRCLE* c1, const CIRCLE* c2)
{
	return is_equal_points(&c1->center, &c2->center);
}
