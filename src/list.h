#ifndef CLIBDSA_LIST_H
#define CLIBDSA_LIST_H

//  __
// |  |
// |  |
// |  |
// |__|
//  __
// |__|
//
// Totally incomplete, work in progress ...

#define List(T) \
typedef struct  { \
    T* data;      \
    size_t len;   \
    size_t cap;   \
} List_##T;       \
                  \
List_##T*

#endif
