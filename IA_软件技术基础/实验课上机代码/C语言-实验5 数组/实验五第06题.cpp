//!这道题用了AI，有时间重新思考

#include <stdio.h>

int main() {
    int num;
    char str[33];
    scanf("%d", &num);

    for (int i = 31; i >= 0; i--)
        str[31 - i] = (num & (1 << i)) ? '1' : '0';

    for (int i = 0; i < 32; i++)
    {
        printf("%c", str[i]);
        if ((i + 1) % 4 == 0 && (i + 1) != 32)
            printf(" ");
    }
    printf("\n");

    return 0;
}