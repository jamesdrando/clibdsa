#ifndef CLIBDSA_ALLOCATION_H
#define CLIBDSA_ALLOCATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numbers.h"

/*
 * This provides a wrapper for malloc, calloc, and free,
 * to provide automatic exit in the event of allocation
 * failure. If this is not desired, then do not use this. :)
 */


static inline void* xmalloc(usize size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed for size %zu\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

static inline void* xcalloc(usize num, usize size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed for %zu elements of size %zu\n", num, size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

static inline void* xrealloc(void *ptr, usize new_size) {
    void* tmp = realloc(ptr, new_size);
    if (tmp == NULL) {
        fprintf(stderr, "Memory reallocation failed for size %zu\n", new_size);
        exit(EXIT_FAILURE);
    }
    return tmp;
}

static inline void xfree(void* ptr) {
    if (ptr == NULL) {
        return; // return silently
    }
    free(ptr);
}

#endif
