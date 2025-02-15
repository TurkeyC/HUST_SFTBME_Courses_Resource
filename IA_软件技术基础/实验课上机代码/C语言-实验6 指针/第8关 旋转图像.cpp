#include <stdio.h>
#include <stdlib.h>

// 读取输入矩阵
void input(int n, int m, int **matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// 输出旋转后的矩阵
void output(int n, int m, int **rotated)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", rotated[i][j]);
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }
}

// 进行逆时针旋转90°
void trans(int **matrix, int n, int m, int **rotated) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rotated[m-j-1][i] = matrix[i][j];
        }
    }
}

void fucmat(int **matrix, int n, int m) {
    int **rotated = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        rotated[i] = (int *)malloc(n * sizeof(int));
    }
    trans(matrix, n, m, rotated);
    output(n, m, rotated);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    input(n, m, matrix);
    fucmat(matrix, n, m);
    return 0;
}