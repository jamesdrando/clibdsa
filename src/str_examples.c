#include <stdio.h>
#include "numbers.h"
#include "str.h"
#include "len.h"

int main() {
    str hello = str_from("Hello!");
    printf("hello->len: %zu\n", hello->len);
    usize hello_len = len(hello);
    str sentence = str_join(3, "Hello", " how ", "are you.");
    char *chars = cstr(sentence);

    printf("%s\n", hello->data);
    printf("%zu\n", hello_len);
    printf("%s\n", sentence->data);
    printf("%s\n", chars);

    str_free(hello);
    str_free(sentence);
    xfree(chars);
    return 0;
}
