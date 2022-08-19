//
// Copyright (c) 2018-2021 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#ifndef ABR_H
#define ABR_H

#include <stdint.h>
#include <stdbool.h>

#ifndef ABR_UNIT_BITSIZE
// modify it to 8, 16, 32, 64, 128... if you need
#define ABR_UNIT_BITSIZE 32
#endif

// The abr_unit is the most basic type of integer the library works on.
// It should be defined as possible the widest integer type your compiller support.
// The abr_halfunit must be two times shorter.
// eg. abr_unit -> uint32_t, abr_halfunit -> uint16_t
#if ABR_UNIT_BITSIZE == 128
#define ABR_UNIT_SIZE 16
typedef uint8_t abr_byte;
typedef uint64_t abr_halfunit;
typedef uint128_t abr_unit;
#elif ABR_UNIT_BITSIZE == 64
#define ABR_UNIT_SIZE 8
typedef uint8_t abr_byte;
typedef uint32_t abr_halfunit;
typedef uint64_t abr_unit;
#elif ABR_UNIT_BITSIZE == 32
#define ABR_UNIT_SIZE 4
typedef uint8_t abr_byte;
typedef uint16_t abr_halfunit;
typedef uint32_t abr_unit;
#elif ABR_UNIT_BITSIZE == 16
#define ABR_UNIT_SIZE 2
typedef uint8_t abr_byte;
typedef uint8_t abr_halfunit;
typedef uint16_t abr_unit;
#elif ABR_UNIT_BITSIZE == 8
#define ABR_UNIT_SIZE 1
typedef uint8_t abr_byte;
typedef uint8_t abr_halfunit;
typedef uint8_t abr_unit;
#else
#error There is no ABR_UNIT_SIZE set. Compile with appropriate flag (eg. -DABR_UNIT_SIZE=32) or modify ABR_UNIT_SIZE in ABR.h
#define ABR_PREPROCESSING_ERROR
#endif /* ABR_UNIT_BITSIZE */

#ifndef ABR_PREPROCESSING_ERROR

// Main type of ABR library
typedef struct abr_t {
    abr_unit *		chain;                  // the buffer for register's value storage
    unsigned int	bitsize;                // size of the register in bits
    bool            is_selfmanaged_chain;   // is the register own the buffer (is responsible for freeing the buffer) 
} abr_t;

// ABR alloc set of functions creates register and allocates buffer for the register (owning the buffer)
abr_t abr_alloc(abr_unit bitsize);
abr_t abr_alloc_copy(abr_t prototype);
void abr_free(abr_t *abr);

// ABR create set of functions creates ABR and store it in given buffer (NOT owning the buffer)
abr_t abr_create(uint8_t *buffer, abr_unit bitsize);
abr_t abr_create_copy(uint8_t *buffer, abr_unit bitsize, abr_t prototype);
abr_t abr_create_empty(void);

#endif  /* ABR_PREPROCESSING_ERROR */

#endif  /* ABR_H */
