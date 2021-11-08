#include <bits/types/FILE.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_processing.h"

void get_array_from_file(float **arr, FILE *file) {
    int row = 0,
            col = 0;
    char *line = NULL;
    size_t len = 0;

    char next_number_in_line[20];
    char next_char_in_line;

    while (getline(&line, &len, file) != -1) {
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
        row++;
        col = 0;
    }
}