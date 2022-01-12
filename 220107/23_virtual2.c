#include <stdio.h>

struct AAA {
    int a;
    char b;
    double c;
};

struct BBB {
    char a;
    double b;
    int c;
} __attribute__((aligned(1), packed));

int main()
{
    printf("%ld\n", sizeof(struct AAA));
    printf("%ld\n", sizeof(struct BBB));

    return 0;
}