#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "param_handling.h"
#include "usage.h"
#include "structs/params.h"

struct Params get_params(char *argv[]) {
    struct Params params;
    params.rows = 0;
    params.cols = 0;
    params.filename = "";

    for (int i = 1; i < 7; i++) {
        if (argv[i][0] != '-') {
            continue;
        }

        switch (argv[i][1]) {
            case 'r':
                params.rows = atoi(argv[i + 1]);
                break;
            case 'c':
                params.cols = atoi(argv[i + 1]);
                break;
            case 'f':
                params.filename = argv[i + 1];
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

    if (params.cols > MAX_COL_NUMBER || params.cols < 1) {
        printf("Invalid col value!\n");
        has_error = true;
    }

    if (params.rows > MAX_ROW_NUMBER || params.rows < 1) {
        printf("Invalid row value!\n");
        has_error = true;
    }

    if (file == NULL) {
        printf("File does not exist or does not readable!\n");
        has_error = true;
    }

    if (has_error) {
        show_usage_and_exit();
    }
}