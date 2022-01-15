#ifndef PARALLEL_ARRAY_PROCESSING_PARAM_HANDLING_H
#define PARALLEL_ARRAY_PROCESSING_PARAM_HANDLING_H

struct Params get_params(char *argv[]);
void validate_params(struct Params params, FILE *input, FILE *output);

#endif //PARALLEL_ARRAY_PROCESSING_PARAM_HANDLING_H