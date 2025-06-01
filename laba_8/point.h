#pragma once
#ifndef POINT_H
#define POINT_H
typedef struct Point {
	double x, y;
}POINT;
void print_point(const POINT* p);
double calculate_distance(const POINT* p1, const POINT* p2);
int is_equal_points(const POINT* p1, const POINT* p2);
#endif
