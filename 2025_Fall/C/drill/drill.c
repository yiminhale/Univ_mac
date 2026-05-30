#include <stdio.h>

int main(){
    struct family {
        char c;
        int i;
        short s;
    };
    struct family f;
    printf("%zu\n", sizeof(f));

    return 0;
}