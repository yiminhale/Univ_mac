#include <stdio.h>

struct Unoptimized {
    char a;
    long long b;
    char c;
    int d;
};

int main(void) {
    struct Unoptimized s;
    //각 멤버의 주소를 본다.
    printf("start address: %p\n",&s);
    printf("&s: %p, size of s: %lu\n", &s, sizeof(s));
    printf("Member Address:\n");
    printf("&a: %p, size of a: %lu\n", &s.a, sizeof(s.a));
    printf("&b: %p, size of b: %lu\n", &s.b, sizeof(s.b));
    printf("&c: %p, size of c: %lu\n", &s.c, sizeof(s.c));
    printf("&d: %p, size of d: %lu\n", &s.d, sizeof(s.d));
    
    return 0;
}