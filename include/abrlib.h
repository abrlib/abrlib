//
// Copyright (c) 2018-2021 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#ifndef ABR_H
#define ABR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#ifndef ABR_UNIT_BITSIZE
// modify it to 8, 16, 32, 64, 128... if you need
#define ABR_UNIT_BITSIZE 32
#endif

// The abrunit_t is the most basic type of integer the library works on.
// It should be defined as possible the widest integer type your compiller support.
// The abrhalfunit_t must be two times shorter.
// eg. abrunit_t -> uint32_t, abrhalfunit_t -> uint16_t
#if ABR_UNIT_BITSIZE == 128
#define ABR_UNIT_SIZE 16
typedef uint8_t abrbyte_t;
typedef uint64_t abrhalfunit_t;
typedef uint128_t abrunit_t;
#elif ABR_UNIT_BITSIZE == 64
#define ABR_UNIT_SIZE 8
typedef uint8_t abrbyte_t;
typedef uint32_t abrhalfunit_t;
typedef uint64_t abrunit_t;
#elif ABR_UNIT_BITSIZE == 32
#define ABR_UNIT_SIZE 4
typedef uint8_t abrbyte_t;
typedef uint16_t abrhalfunit_t;
typedef uint32_t abrunit_t;
#elif ABR_UNIT_BITSIZE == 16
#define ABR_UNIT_SIZE 2
typedef uint8_t abrbyte_t;
typedef uint8_t abrhalfunit_t;
typedef uint16_t abrunit_t;
#elif ABR_UNIT_BITSIZE == 8
#define ABR_UNIT_SIZE 1
typedef uint8_t abrbyte_t;
typedef uint8_t abrhalfunit_t;
typedef uint8_t abrunit_t;
#else
#error There is no ABR_UNIT_SIZE set. Compile with appropriate flag (eg. -DABR_UNIT_SIZE=32) or modify ABR_UNIT_SIZE in ABR.h
#define ABR_PREPROCESSING_ERROR
#endif /* ABR_UNIT_BITSIZE */

#ifndef ABR_PREPROCESSING_ERROR

// aligned bitsize is a bitsize that is multiple of ABR_UNIT_BITSIZE
#define ABR_IS_BITSIZE_ALIGNED(bitsize)             (((bitsize) % ABR_UNIT_BITSIZE == 0 ) ? true : false)

// how many abrunit_t is requred to store the value
#define ABR_MINIMAL_REQUIRED_UNITS(bitsize)         (ABR_IS_BITSIZE_ALIGNED(bitsize) ? (bitsize) : ((bitsize) / ABR_UNIT_BITSIZE) + 1)

// Main type of ABR library
typedef struct abr_t {
    abrunit_t *      chain;                  // the buffer for register's value storage
    abrunit_t        bitsize;                // size of the register in bits
    bool             is_selfmanaged_chain;   // is the register own the buffer (is responsible for freeing the buffer) 
} abr_t;

// ABR alloc set of functions creates register and allocates buffer for the register (owning the buffer)
abr_t abr_alloc(abrunit_t bitsize);
void abr_free(abr_t *abr);

// ABR create set of functions creates ABR and store it in given buffer (NOT owning the buffer)
abr_t abr_create(abrunit_t *buffer, abrunit_t bitsize);
abr_t abr_create_empty(void);

#endif  /* ABR_PREPROCESSING_ERROR */

#ifdef __cplusplus
}
#endif

#endif  /* ABR_H */
