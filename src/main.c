#include <stdio.h>
#include "structs/params.h"
#include "usage.h"
#include "param_handling.h"
#include "file_processing.h"
#include "array_initialization.h"

int main(int argc, char *argv[]) {
    ensure_usage(argc);

    struct Params params = get_params(argv);
    FILE *file = fopen(params.filename, "r");

    validate_params(params, file);
    printf("\nWe will initialize a %d x %d matrix from the file '%s'\n", params.rows, params.cols, params.filename);

    float **array = init_array(params);

    get_array_from_file(array, params, file);

    for (int i = 0; i < params.rows; i++) {
        for (int j = 0; j < params.cols; j++) {
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
