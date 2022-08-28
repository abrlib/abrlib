//
// Copyright (c) 2018-2021 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#ifndef ABRUSLIB_H
#define ABRUSLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#ifndef ABRUS_UNIT_BITSIZE
// modify it to 8, 16, 32, 64, 128... if you need
#define ABRUS_UNIT_BITSIZE 32u
#endif

// The abrusunit_t is the most basic type of integer the library works on.
// It should be defined as possible the widest integer type your compiller support.
// The abrushalfunit_t must be two times shorter.
// eg. abrusunit_t -> uint32_t, abrushalfunit_t -> uint16_t
#if ABRUS_UNIT_BITSIZE == 128u
#define ABRUS_UNIT_SIZE 16u
typedef uint8_t abrusbyte_t;
typedef uint64_t abrushalfunit_t;
typedef uint128_t abrusunit_t;
#elif ABRUS_UNIT_BITSIZE == 64u
#define ABRUS_UNIT_SIZE 8u
typedef uint8_t abrusbyte_t;
typedef uint32_t abrushalfunit_t;
typedef uint64_t abrusunit_t;
#elif ABRUS_UNIT_BITSIZE == 32u
#define ABRUS_UNIT_SIZE 4u
typedef uint8_t abrusbyte_t;
typedef uint16_t abrushalfunit_t;
typedef unsigned int abrusunit_t;
#elif ABRUS_UNIT_BITSIZE == 16u
#define ABRUS_UNIT_SIZE 2u
typedef uint8_t abrusbyte_t;
typedef uint8_t abrushalfunit_t;
typedef uint16_t abrusunit_t;
#elif ABRUS_UNIT_BITSIZE == 8u
#define ABRUS_UNIT_SIZE 1u
typedef uint8_t abrusbyte_t;
typedef uint8_t abrushalfunit_t;
typedef uint8_t abrusunit_t;
#else
#error There is no ABRUS_UNIT_SIZE set. Compile with appropriate flag (eg. -DABRUS_UNIT_SIZE=32) or modify ABRUS_UNIT_SIZE in abruslib.h
#define ABRUS_PREPROCESSING_ERROR
#endif /* ABRUS_UNIT_BITSIZE */

#ifndef ABRUS_PREPROCESSING_ERROR

// aligned bitsize is a bitsize that is multiple of ABRUS_UNIT_BITSIZE
#define ABRUS_IS_BITSIZE_ALIGNED(bitsize)             (((bitsize) % ABRUS_UNIT_BITSIZE == 0) ? true : false)

// how many abrusunit_t is requred to store the value
#define ABRUS_MINIMAL_REQUIRED_UNITS(bitsize)         (ABRUS_IS_BITSIZE_ALIGNED(bitsize) ? (bitsize) : ((bitsize) / ABRUS_UNIT_BITSIZE) + 1)

// Main type of abruslib library
typedef struct {
    abrusunit_t *chain;                      // the buffer for register's value storage
    abrusunit_t  bitsize;                    // size of the register in bits
    bool         is_selfmanaged_chain;       // is the register own the buffer (is responsible for freeing the buffer)
} abrus_t;

// "Alloc" set of functions creates register and allocates buffer for the register (owning the buffer)
abrus_t     abrus_alloc(abrusunit_t bitsize);
void        abrus_free(abrus_t *abrus);

// "Create" set of functions creates register and store it in given buffer (NOT owning the buffer)
abrus_t     abrus_create(abrusunit_t *buffer, abrusunit_t bitsize);
abrus_t     abrus_create_empty(void);

#endif  /* ABRUS_PREPROCESSING_ERROR */

#ifdef __cplusplus
}
#endif

#endif  /* ABRUSLIB_H */
