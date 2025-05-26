#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct {
    double x, y;
    double r;
} Circle;

int is_nested(Circle a, Circle b);
int is_intersect(Circle a, Circle b);
int has_nested(Circle circles[], int n);
int has_three_mutual_intersections(Circle circles[], int n);
int has_lonely(Circle circles[], int n);
int init_circles(Circle circles[], int max_n);
void print_circles(Circle circles[], int n);

#endif // CIRCLE_H
