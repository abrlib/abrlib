#include <stdio.h>
#include "abr.h"

int main() {
    abr_t reg = abr_alloc(32);
    abr_free(&reg);
    return 0;
}