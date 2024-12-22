#include "../include/helper_functions.hpp"

float clamp(float num, float min, float max) {
    if (num < min) return min;
    else if (num > max) return max;
    else return num;
}
