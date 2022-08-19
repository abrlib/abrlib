//
// Copyright (c) 2018-2021 Maciej Gorzkowski
//
// This file is licensed under the MIT License.
// Full license text is available in 'LICENSE'.
//

#ifndef ABR_PRIV_H
#define ABR_PRIV_H

#include "abr.h"

#define BITS_IN_BYTE                        (8)

#define ABR_IS_BITSIZE_VALID(bitsize)       (((bitsize)%sizeof(abr_unit)==0) ? true : false)
#define ABR_ALIGN_BITSIZE(bitsize)          (ABR_IS_BITSIZE_VALID(bitsize) ? (bitsize) : (((bitsize / ABR_UNIT_BITSIZE) + 1) * ABR_UNIT_BITSIZE))

#endif  /* ABR_PRIV_H */