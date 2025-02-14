//!���մ���д��"ʵ����ר�òݸ�ֽ��.cpp"��



#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);

    // �������п��ܵ���λ�����
    for (int numerator = 12345; numerator <= 98765; numerator++) {
        for (int denominator = 12345; denominator <= 98765; denominator++) {
            // �����Ӻͷ�ĸ�Ƿ����ظ�������
            if (numerator % 10 == 0 || denominator % 10 == 0) continue; // ������0��β����

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

            // ���ʹ���˳���10����ͬ�����֣�������
            if (used_digits != (1 << 10) - 1) continue;

            // ����Ƿ���������
            if (numerator * x == denominator) {
                printf("%05d/%05d=%d\n", numerator, denominator, x);
            }
        }
    }

    return 0;
}
