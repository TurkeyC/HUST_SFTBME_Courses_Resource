#include <stdio.h>
#include <string.h>

// 实现乘法
void multiply(char *num1, char *num2, char *result)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i, j, ca, sum;

    // 初始化
    for (i = 0; i < len1 + len2; i++)
    {
        *(result+i) = '0';
    }
    *(result + len1 + len2) = '\0';

    // 逐位相乘
    for (i = len1 - 1; i >= 0; i--)
    {
        ca = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            sum = (*(num1+i) - '0') * (*(num2+j) - '0') + (*(result + i + j + 1) - '0') + ca;
            *(result + i + j + 1) = sum % 10 + '0';
            ca = sum / 10;
        }
        result[i + j + 1] += ca;
    }

    // 去掉前导零
    i = 0;
    while (*(result+i) == '0' && *(result+i+1) != '\0')
    {
        i++;
    }
    memmove(result, result + i, strlen(result) - i + 1);
}

int main() {
    char num1[201], num2[201], result[403];

    scanf("%s%s", num1, num2);

    multiply(num1, num2, result);

    printf("%s\n", result);

    return 0;
}