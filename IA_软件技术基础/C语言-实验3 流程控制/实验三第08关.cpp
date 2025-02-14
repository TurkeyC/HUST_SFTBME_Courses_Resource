#include <stdio.h>

int main() {
    char ch;
    int space_flag = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (!space_flag) {
                putchar(ch);
                space_flag = 1; // 标记遇到的首个空格
            }
        } else {
            putchar(ch);
            space_flag = 0; // 重置标记
        }
    }

    return 0;
}
