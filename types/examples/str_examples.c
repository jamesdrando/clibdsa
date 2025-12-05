#include <stdio.h>
#include "numeric.h"
#include "str.h"

// This is a target for later - will not work yet.
int main() {
    str hello = strf("Hello!");
    usize hello_len = len(hello); // C11 Generic for str match using str_len
    str sentence = join("Hello", " how ", "are you.");
    char *chars = cstr(s);
}
