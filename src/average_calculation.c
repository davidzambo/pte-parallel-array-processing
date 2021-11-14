#include "average_calculation.h"

void get_averages_in_columns(float *sums, float **array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0) {
                sums[j] = 0;
            }
            sums[j] += array[i][j];
            if (i == size - 1) {
                sums[j] /= (float) size;
            }
        }
    }
}