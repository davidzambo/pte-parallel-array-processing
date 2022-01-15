#include <stdio.h>
#include <stdlib.h>
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
    FILE *output = fopen("results.txt", "w");

    validate_params(params, file, output);

    float **array = init_array(params);

    get_array_from_file(array, params, file);
    printf("File processing: %.4fs\n", omp_get_wtime() - start_time);

    float *averages = malloc(params.size * sizeof(float));

    get_averages_in_columns(averages, array, params.size);
    printf("Average calculation: %.4fs\n", omp_get_wtime() - start_time);

    char **results = get_average_indices(averages, array, params.size, params.precision);
    printf("Get matching indexes time: %.4fs\n", omp_get_wtime() - start_time);

    for (int i = 0; i < params.size; i++) {
        fprintf(output, "%s", results[i]);
    }

    fclose(output);

    printf("Running time: %.4fs\n", omp_get_wtime() - start_time);
    return 0;
}
