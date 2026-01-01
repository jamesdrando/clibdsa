#ifndef CLIBDSA_LEN_H
#define CLIBDSA_LEN_H

#include <string.h>
#include "numbers.h"
#include "str.h"

// Add any variable length types here.
#define len(x) (_Generic((x), \
    str: str_length, \
    char*: strlen, \
    const str: str_length, \
    const char*: strlen \
)(x))

#endif
