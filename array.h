#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _my_array{
	int size;
	double *data;
} Array;

void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(const Array *a);

#endif

