//
// Copyright (c) 2018-2022 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "abruslib_priv.h"

// Public functions

// Allocation operations

abrus_t abrus_alloc(abrusunit_t bitsize)
{
    abrusunit_t *buffer = malloc(ABRUS_MINIMAL_REQUIRED_UNITS(bitsize) * sizeof(abrusunit_t));
    abrus_t result = {
        .chain                = buffer,
        .bitsize              = bitsize,
        .is_selfmanaged_chain = true,
    };

    return result;
}

void abrus_free(abrus_t *abrus)
{
    if (abrus->is_selfmanaged_chain == true) {
        free(abrus->chain);
    }
    *abrus = abrus_create_empty();
}

// Creation operations

abrus_t abrus_create(abrusunit_t *buffer, abrusunit_t bitsize)
{
    abrus_t result = {
        .chain                = buffer,
        .bitsize              = bitsize,
        .is_selfmanaged_chain = false,
    };

    return result;
}

abrus_t abrus_create_empty(void)
{
    abrus_t result = {
        .chain                = NULL,
        .bitsize              = 0,
        .is_selfmanaged_chain = false,
    };

    return result;
}
