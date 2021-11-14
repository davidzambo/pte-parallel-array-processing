#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs/params.h"
#include "file_processing.h"

void get_array_from_file(float **arr, struct Params params, FILE *file) {
    int row = 0,
            col = 0;
    char *line = NULL;
    size_t len = 0;

    char next_number_in_line[20];
    char next_char_in_line;

    while (getline(&line, &len, file) != -1) {
        if (row > params.rows - 1) {
            break;
        }
        float number;
        int line_iterator = 0,
                number_as_word_iterator = 0;

        do {
            next_char_in_line = line[0 + line_iterator++];
            if (
                    next_char_in_line != ' ' &&
                    next_char_in_line != '\t' &&
                    next_char_in_line != '\n' &&
                    next_char_in_line != '\0'
                    ) {
                next_number_in_line[number_as_word_iterator++] = next_char_in_line;
                continue;
            }

            if (next_number_in_line[0] == '\0') {
                continue;
            }

            next_number_in_line[number_as_word_iterator] = '\0';
            number = strtof(next_number_in_line, NULL);

            while (number_as_word_iterator > 0) {
                next_number_in_line[number_as_word_iterator--] = '\0';
            }

            next_number_in_line[number_as_word_iterator] = '\0';

            arr[row][col++] = number;

        } while (next_char_in_line != '\n' && next_char_in_line != '\0');

        if (col != params.cols) {
            printf("Error during processing the given file: \n");
            printf("%d. row has %s columns than expected based on the given input parameters", row + 1, (col > params.cols - 1) ? "more" : "less");
            exit(-1);
        }

        row++;
        col = 0;
    }

    if (row != params.rows) {
        printf("Error during processing the given file: \n");
        printf("The file contains %s rows than expected based on the given input parameters", (row > params.rows - 1 ) ? "more" : "less");
        exit(-1);
    }

    fclose(file);
}