#include<stdio.h>

void print(n) {
    int counter = 1;
    int sum = 0;
    while (n) {
        if (n & 1)
            sum += counter;

        n >>= 1;
        counter *= 10;
        if (counter == 10000)
            break;
    }
    printf("%04d\n", sum);
}

int main() {
    unsigned char a = 0x6;
    unsigned char b = 0xA;
    unsigned char c = 0x0;
    unsigned char d = 0x3;
    unsigned char e = 0x9;

    printf("a & b: ");
    print(a & b);
    printf("d | e: ");
    print(d | e);
    printf("a ^ b: ");
    print(a ^ b);
    printf("~a: ");
    print(~a);
    printf("b << e: ");
    print(b << e);
    printf("a & d: ");
    print(a & d);
    printf("a | c: ");
    print(a | c);
    printf("a ^ d: ");
    print(a ^ d);
    printf("~(a^d): ");
    print(~(a^d));
    printf("a >> 2: ");
    print(a >> 2);

    return 0;
}
