#include "array.h"

int main(int argc, char *argv[]) {
	if (argc !=2) {
		printf("usage: %s <size>\n", argv[0]);
		return 1;
	}
	
	int size = atoi(argv[1]);
	if(size <= 0){
		printf("not a valid size\n");
		return 1;
	}
	
	Array *arr = (Array *)malloc(sizeof(Array));
	if (!arr) {
		printf("memory allocation failed");
		return 1;
	}

	arr->size = size;
	arr->data = (double *)malloc(size * sizeof(double));
	if (!arr->data) {
		free(arr);
		printf("memory alocation failed");
		return 1;
	}
	
	int i;
	for (i =0; i < size; i++){
		arr->data[i] = i +1;
	}	

	printf("original array:\n");
	output_array(arr);
	shift_array(arr);
	printf("array after the shift:\n");
	output_array(arr);

	Array *avg_arr = average_adjacent(arr);
	if (avg_arr) {
		printf("average adjacent array: \n");
		output_array(avg_arr);
		free(avg_arr->data);
		free(avg_arr);
	}
	free (arr->data);
	free (arr);
	return 0;
}
