#include <stdio.h>
#include <string.h>
#define CHANGE 0

int main(void)
{
    char str[1001];
    scanf("%[^\n]", str); // %[^\n] 表示读取直到遇到换行符为止的所有字符
#if CHANGE
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    printf("%s", str);
#else
    for(int i = 0; i < strlen(str); i++)
        printf("%c", str[i]);
#endif
    return 0;
}