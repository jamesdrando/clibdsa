#ifndef CLIBDSA_NUMERIC_H
#define CLIBDSA_NUMERIC_H

#include <stdint.h>

typedef size_t   usize;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef float    f32;
typedef double   f64;

typedef union {
    i64 i;
    f64 f;
} number;

number x = new(number, x)





#endif
