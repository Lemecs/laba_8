#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include "Circle.h"
#include <stdio.h>


int init_circles(Circle circles[], int max_n) {
    int n;
    printf("Введите количество окружностей (не более %d): ", max_n);
    scanf("%d", &n);
    if (n > max_n) n = max_n;

    for (int i = 0; i < n; i++) {
        printf("Окружность %d:\n", i + 1);
        printf("  Введите координаты центра (x y): ");
        scanf("%lf %lf", &circles[i].x, &circles[i].y);
        printf("  Введите радиус: ");
        scanf("%lf", &circles[i].r);
    }
    return n;
}

void print_circles(Circle circles[], int n) {
    printf("\nСписок окружностей:\n");
    for (int i = 0; i < n; i++) {
        printf("  #%d: Центр = (%.2f, %.2f), Радиус = %.2f\n",
            i + 1, circles[i].x, circles[i].y, circles[i].r);
    }
}


int is_nested(Circle a, Circle b) {
    double dist = hypot(a.x - b.x, a.y - b.y);
    return dist + b.r < a.r;
}

int is_intersect(Circle a, Circle b) {
    double dist = hypot(a.x - b.x, a.y - b.y);
    return fabs(a.r - b.r) <= dist && dist <= (a.r + b.r);
}

int has_nested(Circle circles[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && is_nested(circles[i], circles[j])) {
                return 1;
            }
        }
    }
    return 0;
}

int has_three_mutual_intersections(Circle circles[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (is_intersect(circles[i], circles[j]) &&
                    is_intersect(circles[i], circles[k]) &&
                    is_intersect(circles[j], circles[k])) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int has_lonely(Circle circles[], int n) {
    for (int i = 0; i < n; i++) {
        int intersects = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && is_intersect(circles[i], circles[j])) {
                intersects = 1;
                break;
            }
        }
        if (!intersects) {
            return 1;
        }
    }
    return 0;
}
