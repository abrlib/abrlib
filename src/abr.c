//
// Copyright (c) 2018-2022 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "abr_priv.h"

// Public functions

// Allocation operations

abr_t abr_alloc(abr_unit bitsize)
{
    uint8_t *buffer = malloc(ABR_ALIGN_BITSIZE(bitsize) / BITS_IN_BYTE);
    abr_t result = {
        .chain =  (abr_unit*) buffer,
        .bitsize = bitsize,
        .is_selfmanaged_chain = true,
    };
    return result;
}

void abr_free(abr_t *abr)
{
    if (abr->is_selfmanaged_chain == true) {
        free(abr->chain);
    }
    *abr = abr_create_empty();
}

// Creation operations

abr_t abr_create(uint8_t *buffer, abr_unit bitsize)
{
    bitsize = ABR_ALIGN_BITSIZE(bitsize);
    abr_t result = {
        .chain = (abr_unit*) buffer,
        .bitsize = bitsize,
        .is_selfmanaged_chain = false,
    };
    return result;
}

abr_t abr_create_empty(void)
{
    abr_t result = {
        .chain = NULL,
        .bitsize = 0,
        .is_selfmanaged_chain = false,
    };
    return result;
}
