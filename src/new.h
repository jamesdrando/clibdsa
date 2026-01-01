#ifndef CLIBDSA_NEW_H
#define CLIBDSA_NEW_H

#include <stdarg.h>

#define new(T, ...) New_##T(__VA_ARGS__)

#endif
