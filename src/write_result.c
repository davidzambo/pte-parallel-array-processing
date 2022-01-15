#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include "write_result.h"
#include "float_handler.h"

char ** get_average_indices(float *averages, float **array, int size, int precision) {
    int i, j;
    unsigned long required_line_length;
    char **results = malloc(size * sizeof(char *));
    char *column, *index;

    {
#pragma omp parallel for private(j, column, index, required_line_length)
        for(i = 0; i < size; i++) {
            column = malloc(30 * sizeof (char*));
            index = malloc(5 * sizeof (char*));
            sprintf(column, "Column %d | average = %f: ", i + 1, averages[i]);
            for (j = 0; j < size; j++) {
                if (are_floats_equal(array[j][i], averages[i], precision)) {
                    sprintf(index, "%d ", j);
                    required_line_length = strlen(column) + strlen(index) + 1;
                    column = realloc(column, required_line_length * sizeof(char*));
                    strcat(column, index);
                }
            }
            strcat(column, "\n");
            results[i] = column;
        }
    }
    return results;
}

