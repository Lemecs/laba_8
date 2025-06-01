#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "circle_array.h"
int main()
{
	srand(time(0));
	fill_circle_array(10, 5, 5, 11);
	print_circle_array();
	find_concentric();
	return 0;
}
