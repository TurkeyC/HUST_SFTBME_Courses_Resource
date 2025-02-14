#include <stdio.h>

int RemoveSame(int *a, int n)
{
    int i = 0, j = 0;
    for (i = 1; i < n; i++)
    {
        if (*(a+j) != *(a+i))
        {
            j++;
            *(a+j) = *(a+i);
        }
    }
    return j + 1; // 返回去重后的长度
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", (a+i));
    }

    int new_length = RemoveSame(a, n);

    for (int i = 0; i < new_length; i++) {
        printf("%d", *(a+i));
        if(i != new_length-1) printf(" ");
    }
    printf("\n");
    printf("%d\n", new_length);

    return 0;
}