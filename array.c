#include "array.h"

void output_array(Array *a) {
	if (a == NULL || a->data == NULL) {
		printf("Invalid array\n");
		return;
	}
	for (int i=0; i < a->size; i++){
		printf("%.2f ", a-> data[i]);
	}
	printf("\n");
}

void shift_array (Array *a){
	if ((a == NULL || a->data == NULL || a->size < 2)){
		return;
	}
	double first = a->data[0];
	int i;
	for (i = 0; i < a->size - 1; i++){
		a->data[i] = a->data [i+1];
	}
	a->data[a->size - 1] = first;
}

Array *average_adjacent(const Array *a) {
	if (a==NULL || a->data==NULL || a->size <2) return NULL;
	int new_size = a->size /2;
	Array *new_array = (Array *)malloc(sizeof(Array));
	if (!new_array) return NULL;
	new_array->size = new_size;
	new_array->data = (double *)malloc(new_size*sizeof(double));
	if (!new_array->data) {
		free(new_array);
		return NULL;
	}

	for (int i=0; i < new_size; i++){
		new_array->data[i] = (a->data[2 * i] + a->data[2 * i +1]) / 2.0;
	}
	return new_array;
}
