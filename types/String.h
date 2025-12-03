#ifndef CLIBDSA_STR_H
#define CLIBDSA_STR_H

#include <stdlib.h>
#include <string.h>
#include "numeric.h"
#include "allocation.h"

#ifndef CLIBDSA_DEFAULT_STRING_BUFFER
#define CLIBDSA_DEFAULT_STRING_BUFFER 16
#endif

typedef struct {
    char *str;
    usize len;
    usize cap;
} String;

static inline String* new_String(void) {
    String *s = (String *)xmalloc(sizeof *s);
    s->str = (char *)xcalloc(CLIBDSA_DEFAULT_STRING_BUFFER, 1);
    s->len = 0;
    s->cap = CLIBDSA_DEFAULT_STRING_BUFFER;
    return s;
}

#endif
