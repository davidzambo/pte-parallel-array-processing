#include <malloc.h>
#include "structs/params.h"
#include "array_initialization.h"

float ** init_array(struct Params params) {
    float **array = malloc(params.rows * sizeof(float *));

    for (int i = 0; i < params.rows; i++)
        array[i] = malloc(params.cols * sizeof(float));

    return array;
}