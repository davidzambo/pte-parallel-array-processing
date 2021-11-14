#include <stdio.h>
#include <stdlib.h>
#include "structs/params.h"
#include "usage.h"
#include "param_handling.h"
#include "file_processing.h"
#include "array_initialization.h"
#include "average_calculation.h"
#include "write_result.h"

int main(int argc, char *argv[]) {
    ensure_usage(argc);

    struct Params params = get_params(argv);
    FILE *file = fopen(params.filename, "r");

    validate_params(params, file);

    float **array = init_array(params);

    get_array_from_file(array, params, file);

    float *averages = malloc(params.size * sizeof(float));

    get_averages_in_columns(averages, array, params.size);

    write_out_indices(averages, array, params.size);

    return 0;
}
