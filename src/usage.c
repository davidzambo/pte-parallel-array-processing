#include <stdio.h>
#include <stdlib.h>
#include "usage.h"

void show_usage_and_exit() {
    printf("Usage: ");
    printf("\tparallel-array-processor -n 4 -f array_example.txt\n");
    printf("\t\t -n\tsize of the vector\n");
    printf("\t\t\tINTEGER, min 1, max %d\n", MAX_VECTOR_SIZE);
    printf("\t\t -f\tpath to the source data file\n");
    printf("\t\t\tPLAIN TEXT file with TAB separated FLOAT records\n");
    exit(-1);
}

void ensure_usage(int argc) {
    if (argc != 5) {
        show_usage_and_exit();
    }
}