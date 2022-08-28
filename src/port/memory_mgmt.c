//
// Copyright (c) 2018-2022 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#include <stdlib.h>
#include <stdint.h>

#include "memory_mgmt.h"

// __attribute__((weak))
void *abrus_bufferalloc(uint32_t elements, uint32_t elements_size)
{
    // This call breaks [misra-c2012-10.4]
    return calloc(elements, elements_size);
}

// __attribute__((weak))
void abrus_bufferfree(void *pointer)
{
    // This call breaks [misra-c2012-10.4]
    free(pointer);
}
