//!这道题用了AI，有时间重新思考

#include <stdio.h>
#include <string.h>

void strnins(char t[], char s[], int n) {

    // if (n > strlen(t))
    //     n = strlen(t);

    for (int i = strlen(t); i >= n; i--)
        t[i + strlen(s)] = t[i];

    for (int i = 0; i < strlen(s); i++)
        t[n + i] = s[i];
}

int main() {
    char t[1000], s[1000];
    int n;
    scanf("%s %s %d", t, s, &n);
    strnins(t, s, n);
    printf("%s", t);
    return 0;
}
