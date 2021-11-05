
#include <stdio.h>
#include <stdlib.h>
#include "usage.h"

void show_usage_and_exit() {
    printf("Usage: ");
    printf("\tparallel-array-processor -r 3 -c 4 -f array_example.txt\n");
    printf("\t\t -r\tnumber of ROWS of the array\n");
    printf("\t\t\tINTEGER, min 1, max %d\n", MAX_ROW_NUMBER);
    printf("\t\t -c\tnumber of COLUMNS of the array\n");
    printf("\t\t\tINTEGER, min 1, max %d\n", MAX_COL_NUMBER);
    printf("\t\t -f\tpath to the source data file\n");
    printf("\t\t\tPLAIN TEXT file with TAB separated FLOAT records\n");
    exit(-1);
}

void ensure_usage(int argc) {
    if (argc != 7) {
        show_usage_and_exit();
    }
}