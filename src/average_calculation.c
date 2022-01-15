#include "average_calculation.h"

void get_averages_in_columns(float *averages, float **array, int size) {
    double sum;
    for (int i = 0; i < size; i++) {
        sum = 0.0;
        for (int j = 0; j < size; j++) {
            sum += array[j][i];
        }
        averages[i] = (float) sum / (float) size;
    }
}