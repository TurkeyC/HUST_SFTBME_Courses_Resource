#include <stdio.h>

int main() {
    char ch;
    int space_flag = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (!space_flag) {
                putchar(ch);
                space_flag = 1; // ����������׸��ո�
            }
        } else {
            putchar(ch);
            space_flag = 0; // ���ñ��
        }
    }

    return 0;
}
