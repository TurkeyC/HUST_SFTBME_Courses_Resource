#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_asc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compare_desc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

void sort_numbers(int *arr, int n, int des)
{
    if (des)
        qsort(arr, n, sizeof(int), compare_desc);
    else
        qsort(arr, n, sizeof(int), compare_asc);
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);

    int des = 0;
    if (argc == 3 && strcmp(argv[2], "-d") == 0)
        des = 1;

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort_numbers(arr, n, des);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}