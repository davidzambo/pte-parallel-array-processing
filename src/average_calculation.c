#include "average_calculation.h"

void get_averages_in_columns(float *sums, float **array, int size) {

    int i, j;
    double sum;
    {
#pragma omp for private(j, sum)
        for (i = 0; i < size; i++) {
            sum = 0.0;
            for (j = 0; j < size; j++) {
                sum += array[j][i];
            }
            sums[i] = sum / size;
        }
    }
}