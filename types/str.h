#ifndef CLIBDSA_STR_H
#define CLIBDSA_STR_H

#include <stdlib.h>
#include <string.h>
#include "numbers.h"
#include "allocation.h"

#ifndef       CLIBDSA_DEFAULT_STR_BUFFER
    #define   CLIBDSA_DEFAULT_STR_BUFFER 16
#endif     /* CLIBDSA_DEFAULT_STR_BUFFER   */

typedef struct {
    char *data;
    usize len;
    usize cap;
} _str;

typedef _str* str;

static inline str newstr(void) {
    str s = (str)xmalloc(sizeof *s);
    s->data = (char *)xcalloc(CLIBDSA_DEFAULT_STR_BUFFER, 1);
    s->len = 0;
    s->cap = CLIBDSA_DEFAULT_STR_BUFFER;
    return s;
}

// Alias to allow using the new() macro, ie. new(str)
#define New_str() newstr()

static inline str strf(char *c) {
    str s = (str)xmalloc(sizeof *s);
    usize len = strlen(c);
    s->data = c;
    s->len = len;
    s->cap = len;
    return s;
}

// Returns a reference to the c str (char *)
static inline char* cstr(str s) {
    return s->data;
}

// Destroys the str struct and returns the c str (char *)
static inline char* destr(str s) {
    char *c = s->data;
    xfree(s);
    return c;
}

// Needs to be finished
static inline str str_join(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)


}

#endif /* CLIBDSA_STR_H */



// // Variadic function to print given arguments
// void print(int n, ...) {
//     va_list args;
//     va_start(args, n);
//     for (int i = 0; i < n; i++)
//         printf("%d ", va_arg(args, int));
//     printf("\n");
//     va_end(args);
// }
