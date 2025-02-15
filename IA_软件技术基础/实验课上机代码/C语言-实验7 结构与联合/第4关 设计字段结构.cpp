#include <stdio.h>

struct bits {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
};

void f0(int b) {
    printf("the function %d is called!\n", b);
}
void f1(int b) {
    printf("the function %d is called!\n", b);
}
void f2(int b) {
    printf("the function %d is called!\n", b);
}
void f3(int b) {
    printf("the function %d is called!\n", b);
}
void f4(int b) {
    printf("the function %d is called!\n", b);
}
void f5(int b) {
    printf("the function %d is called!\n", b);
}
void f6(int b) {
    printf("the function %d is called!\n", b);
}
void f7(int b) {
    printf("the function %d is called!\n", b);
}

void (*p_fun[8])(int) = {f0, f1, f2, f3, f4, f5, f6, f7};

int main() {
    struct bits Bit = {0};
    int ins;

    scanf("%d", &ins);

    Bit.bit0 = ins & 1;
    Bit.bit1 = (ins >> 1) & 1;
    Bit.bit2 = (ins >> 2) & 1;
    Bit.bit3 = (ins >> 3) & 1;
    Bit.bit4 = (ins >> 4) & 1;
    Bit.bit5 = (ins >> 5) & 1;
    Bit.bit6 = (ins >> 6) & 1;
    Bit.bit7 = (ins >> 7) & 1;

    for (int i = 0; i < 8; ++i)
        if (((ins >> i) & 1) == 1)
            p_fun[i](i);

    return 0;
}