//!最终代码写在"实验三专用草稿纸三.cpp"中



#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);

    // 遍历所有可能的五位数组合
    for (int numerator = 12345; numerator <= 98765; numerator++) {
        for (int denominator = 12345; denominator <= 98765; denominator++) {
            // 检查分子和分母是否有重复的数字
            if (numerator % 10 == 0 || denominator % 10 == 0) continue; // 跳过以0结尾的数

            int used_digits = 0;
            int temp = numerator;
            while (temp > 0) {
                used_digits |= 1 << (temp % 10);
                temp /= 10;
            }
            temp = denominator;
            while (temp > 0) {
                used_digits |= 1 << (temp % 10);
                temp /= 10;
            }

            // 如果使用了超过10个不同的数字，则跳过
            if (used_digits != (1 << 10) - 1) continue;

            // 检查是否满足条件
            if (numerator * x == denominator) {
                printf("%05d/%05d=%d\n", numerator, denominator, x);
            }
        }
    }

    return 0;
}
