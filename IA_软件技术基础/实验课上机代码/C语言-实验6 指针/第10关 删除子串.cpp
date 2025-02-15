#include <stdio.h>
#include <string.h>

int dels(char *str, const char *subs)
{
    char *pos;
    int mar = 0;
    unsigned long long len = strlen(subs);

    char *result = str;
    char *dst = result;
    char *src = str;

    while (*src != '\0') {
        if (strncmp(src, subs, len) == 0)
        {
            mar = 1;
            src += len;
        }
        else
            *dst++ = *src++;
    }
    *dst = '\0';
    return mar;
}

int main() {
    char str[100];
    char subs[100];

    fgets(str, sizeof(str), stdin);
    fgets(subs, sizeof(subs), stdin);

    int result = dels(str, subs);
    printf("%s%d", str, result);

    return 0;
}