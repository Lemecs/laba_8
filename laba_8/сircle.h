#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"
typedef struct Circle {
	POINT center;
	double radius;
}CIRCLE;
void print_circle(const CIRCLE* c);
int is_equal_circle(const CIRCLE* c1, const CIRCLE* c2);
int is_concetric(const CIRCLE* c1, const CIRCLE* c2);
#endif
