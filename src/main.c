#include <stdio.h>
#include <stdlib.h>
#include "structs/params.h"
#include "usage.h"
#include "param_handling.h"


float *get_array_from_file(struct Params params, FILE *file) {
    float arr[params.rows][params.cols];
    int line_iterator = 0,
    i = 0,
    j = 0,
    c = 0;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char next_number_in_line[255];

    while ((read = getline(&line, &len, file)) != -1) {
        printf("\nlength: %zd | %zu | %s", read, len, line);
        line_iterator = 0;

        while (1) {
            next_number_in_line[c++] = *(line + line_iterator++);
            char *next_char = next_number_in_line + line_iterator - 1;
            float number;

            if (next_char == '\t' || next_char == '\n') {
                number = strtof(next_number_in_line, NULL);
                arr[i][j++] = number;
                if (next_char == '\n') {
                    break;
                }
            }
        }
        i++;
        j = 0;
    }

    return &arr;
}

int main(int argc, char *argv[]) {
    ensure_usage(argc);

    struct Params params = get_params(argv);
    FILE *file = fopen(params.filename, "r");

    validate_params(params, file);
    printf("\nWe will initialize a %d x %d matrix from the file '%s'", params.cols, params.rows, params.filename);


    float *arr = get_array_from_file(params, file);

    return 0;
}
