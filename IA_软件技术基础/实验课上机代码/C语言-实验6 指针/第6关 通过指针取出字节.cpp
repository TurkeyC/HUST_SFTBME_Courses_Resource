#include <stdio.h>

void display_hex(int num) {
    unsigned char *ptr = (unsigned char *)&num;
    int i;

    for (i = sizeof(int) - 1; i >= 0; i--) {
        printf("%01x %01x", (*(ptr + i) >> 4) & 0xF, *(ptr + i) & 0xF);
        if (i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int number;
    scanf("%d", &number);
    display_hex(number);
    return 0;
}