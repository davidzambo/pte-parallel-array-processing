#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs/params.h"
#include "usage.h"
#include "param_handling.h"
#include "file_processing.h"
#include "array_initialization.h"
#include "average_calculation.h"
#include "write_result.h"
#include "omp.h"

int main(int argc, char *argv[]) {
    double start_time = omp_get_wtime();
    ensure_usage(argc);

    struct Params params = get_params(argv);
    FILE *file = fopen(params.filename, "r");

    validate_params(params, file);

    float **array = init_array(params);

    get_array_from_file(array, params, file);
    printf("File processing: %.4fs\n", omp_get_wtime() - start_time);

    float *averages = malloc(params.size * sizeof(float));

    get_averages_in_columns(averages, array, params.size);

    printf("Average calculation: %.4fs\n", omp_get_wtime() - start_time);

    write_out_indices(averages, array, params.size, params.precision);

    printf("Running time: %.4fs\n", omp_get_wtime() - start_time);
    return 0;
}
