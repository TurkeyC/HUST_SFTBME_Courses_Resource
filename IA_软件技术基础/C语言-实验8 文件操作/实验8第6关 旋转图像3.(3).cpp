#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int n, m;
    int **matrix;
    int i, j;

    char i_filepath[100];
    if (scanf("%s", i_filepath) != 1) {
        perror("读取文件路径失败");
        return 1;
    }

    // 打开输入文件
    inputFile = fopen(i_filepath, "r");
    if (inputFile == NULL) {
        perror("无法打开输入文件");
        return 1;
    }

    // 读取矩阵的行数和列数
    fscanf(inputFile, "%d %d", &n, &m);

    // 动态分配内存给矩阵
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    // 读取矩阵数据
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }

    // 关闭输入文件
    fclose(inputFile);

    // 打开输出文件
    outputFile = fopen("matrix.out", "w");
    if (outputFile == NULL) {
        perror("无法打开输出文件");
        return 1;
    }

    // 将矩阵逆时针旋转90°并写入输出文件
    for (j = m-1; j >= 0; j--) {
        for (i = 0; i < n; i++) {
            fprintf(outputFile, "%d", matrix[i][j]);
            if(i != n-1) fprintf(outputFile, " ");
        }
        fprintf(outputFile, "\n");
    }

    // 关闭输出文件
    fclose(outputFile);

    // 释放动态分配的内存
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}