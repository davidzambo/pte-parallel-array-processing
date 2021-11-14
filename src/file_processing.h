#ifndef PARALLEL_ARRAY_PROCESSING_FILE_PROCESSING_H
#define PARALLEL_ARRAY_PROCESSING_FILE_PROCESSING_H
#include <stdbool.h>

bool is_whitespace(char next_char_in_line);
void get_array_from_file(float **arr, struct Params params, FILE *file);

#endif //PARALLEL_ARRAY_PROCESSING_FILE_PROCESSING_H
