#include "circle_array.h"
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Circle_arraay {
	CIRCLE circles[MAX_SIZE];
	int top;
}ca;
void fill_circle_array(int n, int dx, int dy, int dr)
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
        ca.circles[ca.top].radius = rand() % dr - dr / 2;
    }
}
void print_circle_array()
{
	printf("Array of circles:\n");
	for (int i = 0; i < ca.top; ++i)
	{
		printf("Circle %d\n", i + 1);
		print_circle(&ca.circles[i]);
		printf("***********************\n");
	}
}
static int isNested(const CIRCLE* A, const CIRCLE* B) {
    double dist = calculate_distance(&A->center, &B->center);
    double rmin = (A->radius < B->radius ? A->radius : B->radius);
    double rmax = (A->radius > B->radius ? A->radius : B->radius);
    return (dist + rmin) < rmax;
}
static int isIntersect(const CIRCLE* A, const CIRCLE* B) {
    double dist = calculate_distance(&A->center, &B->center);
    double dr = fabs(A->radius - B->radius);
    double sr = (A->radius + B->radius);
    return (dr <= dist) && (dist <= sr);
}
void checkNested() {
    int n = ca.top;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isNested(&ca.circles[i], &ca.circles[j])) {
                printf("There are at least two nested circles in the array.\n");
                return;
            }
        }
    }
    printf("There are no nested circles in the array.\n");
}
void checkThreePairwiseIntersecting() {
    int n = ca.top;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!isIntersect(&ca.circles[i], &ca.circles[j]))
                continue;
            for (int k = j + 1; k < n; ++k) {
                if (isIntersect(&ca.circles[i], &ca.circles[k]) &&
                    isIntersect(&ca.circles[j], &ca.circles[k])) {
                    printf("There are three pairwise intersecting circles in the array.\n");
                    return;
                }
            }
        }
    }
    printf("There are no three pairwise intersecting circles in the array.\n");
}
void checkIsolated() {
    int n = ca.top;
    for (int i = 0; i < n; ++i) {
        int isolated = 1;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            double dist = calculate_distance(&ca.circles[i].center, &ca.circles[j].center);
            if (dist <= (ca.circles[i].radius + ca.circles[j].radius)) {
                isolated = 0;
                break;
            }
        }
        if (isolated) {
            printf("There is at least one isolated circle in the array.\n");
            return;
        }
    }
    printf("There are no isolated circles in the array.\n");
}