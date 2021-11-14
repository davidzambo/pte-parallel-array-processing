#include <malloc.h>
#include "structs/params.h"
#include "array_initialization.h"

float ** init_array(struct Params params) {
    float **array = malloc(params.size * sizeof(float *));

    for (int i = 0; i < params.size; i++)
        array[i] = malloc(params.size * sizeof(float));

    return array;
}