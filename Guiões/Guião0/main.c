#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int vector[50000];

int main() {
	fill (vector, 50000, 154);
	int x = find (vector, 50000, 154);
	int y = find (vector, 50000, 43);
	printf ("%d, %d\n", x,y);
	return 0;
}