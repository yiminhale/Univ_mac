#include <stdio.h>

struct optimized {
    long long b;
    int d;
    char a;
    char c;
};

int main(void) {
    struct optimized s;
    //각 멤버의 주소를 본다.
    printf("start address: %p\n",&s);
    printf("&s: %p, size of s: %lu\n", &s, sizeof(s));
    printf("Member Address:\n");
    printf("&b: %p, size of b: %lu\n", &s.b, sizeof(s.b));
    printf("&d: %p, size of d: %lu\n", &s.d, sizeof(s.d));
    printf("&a: %p, size of a: %lu\n", &s.a, sizeof(s.a));
    printf("&c: %p, size of c: %lu\n", &s.c, sizeof(s.c));
    
    return 0;
}