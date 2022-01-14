#include <omp.h>
#include <stdio.h>
#include "average_calculation.h"

void get_averages_in_columns(float *sums, float **array, int size) {

    int i, j;
    double sum;
    {
#pragma omp parallel for private(j, sum)
        for (i = 0; i < size; i++) {
            printf("Hello %d in the %d thread\n", i, omp_get_thread_num());

//#pragma omp parallel for
            sum = 0.0;
            for (j = 0; j < size; j++) {
                sum += array[j][i];
//                printf("\n%d %d %f %f", i, j, sum, array[j][i]);
            }
            sums[i] = sum / size;
//            printf("\naverage is %f\n", averages[i]);
//            printf("\n%d %d %f %d", i, j, averages[j], sum);
        }
    }
}