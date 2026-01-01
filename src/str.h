#ifndef CLIBDSA_STR_H
#define CLIBDSA_STR_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "numbers.h"
#include "xalloc.h"

#ifndef       CLIBDSA_DEFAULT_STR_BUFFER
    #define   CLIBDSA_DEFAULT_STR_BUFFER 16
#endif     /* CLIBDSA_DEFAULT_STR_BUFFER   */

// Container to hold string data
// O(n) on init / O(1) bounds checking
typedef struct {
    char *data;
    usize len;
    usize cap;
} _str;

// For simplicity and uniformity, all _str will exist on the heap.
// As such, we'll alias the pointer type ergonomically as 'str'
typedef _str* str;

// New str with default buffer
static inline str newstr(void) {
    str s = (str)xmalloc(sizeof *s);
    s->data = (char *)xcalloc(CLIBDSA_DEFAULT_STR_BUFFER, 1);
    s->len = 0;
    s->cap = CLIBDSA_DEFAULT_STR_BUFFER;
    return s;
}

// Alias to allow using the new() macro, ie. new(str)
#define New_str() newstr()

// str from char* - copies data
static inline str str_from(const char *c) {
    str s = (str)xmalloc(sizeof *s);
    usize len = strlen(c);
    usize cap = len + 1;

    // Copy the string to take ownership of the data
    s->data = (char*)xmalloc(cap);
    memcpy(s->data, c, len);

    s->len = len;
    s->cap = cap;
    return s;
}

// Returns the char* from the data field.
static inline char* str_data(str s) {
    return s->data;
}

// Returns str length (s->len).
static inline usize str_length(str s) {
    return s->len;
}

// str or char* in, char* out.
#define cstr(x) _Generic((x), \
    str: str_data(x), \
    char*: (x), \
    const char*: (x) \
)

// Unwraps and destroys the str container.
static inline char* str_unwrap(str s) {
    char *c = s->data;
    xfree(s);
    return c;
}

// Deep clean: Frees wrapper AND data
static inline void str_free(str s) {
    if (s->data) xfree(s->data);
    xfree(s);
}

// Grow as needed - doubling in size each time.
static inline void str_grow(str s, usize needed) {
    // Check if we already have enough space (including null terminator)
    if (s->len + needed + 1 <= s->cap) {
        return;
    }

    usize new_cap = s->cap;
    while (new_cap < s->len + needed + 1) {
        new_cap = (new_cap > 0) ? new_cap * 2 : CLIBDSA_DEFAULT_STR_BUFFER;
    }

    s->data = (char *)xrealloc(s->data, new_cap);
    s->cap = new_cap;
}

// Raw char* append logic for str
static inline void str_cat_cstr(str s, const char *append) {
    if (!append) return;
    usize len = strlen(append);
    str_grow(s, len);
    memcpy(s->data + s->len, append, len);
    s->len += len;
    s->data[s->len] = '\0';
}

// str appended to str
static inline void str_cat_str(str s, str append) {
    if (!append) return;
    str_grow(s, append->len);
    memcpy(s->data + s->len, append->data, append->len);
    s->len += append->len;
    s->data[s->len] = '\0';
}

// This acts as a switch statement at compile time.
// If the second argument is a string literal or char*, call _cstr.
// If the second argument is a 'str' struct, call _str.
#define str_cat(dest, src) _Generic((src), \
    char*: str_cat_cstr, \
    const char*: str_cat_cstr, \
    str: str_cat_str \
)(dest, src)


// Joins 'n' strings together into a new dynamic string.
//
// Note: When using with str,  you can wrap each argument
// in cstr() for safety.
//
// Example -------------------------
// str s = str_from("Hello world!");
// char* cs = "Hey world!";
// str_join(2, cstr(s), cstr(cs));
static inline str str_join(int n, ...) {
    str s = newstr();

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        char *arg = va_arg(args, char*);
        str_cat(s, arg);
    }

    va_end(args);
    return s;
}

// static inline _str_split_str(str string, char delimeter) {

// }

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
