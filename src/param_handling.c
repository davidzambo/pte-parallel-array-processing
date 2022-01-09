#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "param_handling.h"
#include "usage.h"
#include "structs/params.h"

struct Params get_params(char *argv[]) {
    struct Params params;
    params.size = 0;
    params.precision = 3;
    params.filename = "";

    for (int i = 1; i < 5; i++) {
        if (argv[i][0] != '-') {
            continue;
        }

        switch (argv[i][1]) {
            case 'n':
                params.size = atoi(argv[i + 1]);
                break;
            case 'f':
                params.filename = argv[i + 1];
                break;
            case 'p':
                params.precision = atoi(argv[i + 1]);
                break;
            default:
                printf("Invalid input parameters!\n");
                show_usage_and_exit();
        }
    }
    return params;
}

void validate_params(struct Params params, FILE *file) {
    bool has_error = false;

    if (params.size > MAX_VECTOR_SIZE || params.size < 1) {
        printf("Invalid vector size! Vector should be max %d x %d!\n", MAX_VECTOR_SIZE, MAX_VECTOR_SIZE);
        has_error = true;
    }

    if (file == NULL) {
        printf("File doesn't exist or doesn't readable!\n");
        has_error = true;
    }

    if (has_error) {
        show_usage_and_exit();
    }
}