#include <stdio.h>
#include "abruslib.h"

int main() {
    abrus_t reg = abrus_alloc(32);
    abrus_free(&reg);
    return 0;
}