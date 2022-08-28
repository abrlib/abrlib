//
// Copyright (c) 2018-2022 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#ifndef MEMORY_MGMT_H
#define MEMORY_MGMT_H

// function responsible for allocating memory
// __attribute__((weak))
void *abrus_bufferalloc(uint32_t elements, uint32_t elements_size);

// function responsible for freeing previously allocated memory
// __attribute__((weak))
void abrus_bufferfree(void *pointer);

#endif  /* MEMORY_MGMT_H */
