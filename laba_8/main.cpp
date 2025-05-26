#include <stdio.h>
#include "Circle.h"
#include <locale.h>
#define MAX_CIRCLES 100
#define _CRT_SECURE_NO_WARNINGS
int main() {
    char* locale = setlocale(LC_ALL, "");
    Circle circles[MAX_CIRCLES];
    int n = init_circles(circles, MAX_CIRCLES);
    print_circles(circles, n);
    printf("Есть вложенные окружности: %s\n", has_nested(circles, n) ? "Да" : "Нет");
    printf("Есть три попарно пересекающихся окружности: %s\n", has_three_mutual_intersections(circles, n) ? "Да" : "Нет");
    printf("Есть уединенная окружность: %s\n", has_lonely(circles, n) ? "Да" : "Нет");
    return 0;
}
