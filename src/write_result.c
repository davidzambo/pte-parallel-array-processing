#include <stdio.h>
#include <stdlib.h>
#include "write_result.h"
#include "float_handler.h"

void write_out_indices(float *averages, float **array, int size, int precision) {
    FILE *output = fopen("results.txt", "w");

    if (output == NULL) {
        printf("Output file can't be opened\n");
        exit(-1);
    }

    fprintf(output,"Indices with the equal value of the average in the column\n");
    for(int i = 0; i < size; i++) {
        fprintf(output, "Column %d | average = %f: ", i + 1, averages[i]);
        for (int j = 0; j < size; j++) {
            if (are_floats_equal(array[j][i], averages[i], precision)) {
                fprintf(output,"%d, ", j);
            }
        }
        fprintf(output, "\n");
    }
    fclose(output);
}
