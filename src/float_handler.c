#include <math.h>
#include "float_handler.h"

bool are_floats_equal(float a, float b, int precision) {
    int aInt = (int) (a * pow(10.0, precision));
    int bInt = (int) (b * pow(10.0, precision));
    return aInt == bInt;
}