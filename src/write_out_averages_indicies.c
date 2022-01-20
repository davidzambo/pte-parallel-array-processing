#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write_out_averages_indicies.h"
#include "float_handler.h"

void write_out_average_indices(FILE *output, float *averages, float **array, int size, int precision) {
    int i, j;
    char *column, *index;

    {
#pragma omp for private(j, column, index) ordered
        for(i = 0; i < size; i++) {
            column = malloc(3000 * sizeof (char*));
            index = malloc(5 * sizeof (char*));
            sprintf(column, "Column %d | average = %f: ", i + 1, averages[i]);
            for (j = 0; j < size; j++) {
                if (are_floats_equal(array[j][i], averages[i], precision)) {
                    sprintf(index, "%d ", j);
                    strcat(column, index);
                }
            }
            strcat(column, "\n");

            fprintf(output, "%s", column);
        }
    }
}

