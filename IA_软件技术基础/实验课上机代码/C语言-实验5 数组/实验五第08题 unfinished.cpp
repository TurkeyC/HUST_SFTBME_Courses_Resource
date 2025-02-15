//! 啊？ 过不去？


#include <stdio.h>
#include <string.h>

/*
 * input函数用于输入学生姓名和成绩，并保存到数组中
 * @param name 学生姓名
 * @param score 学生成绩
 * @param n 学生数
 */
void input(char name[][50], int score[], int *n)
{
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
        scanf("%s %d", name[i], &score[i]);
}

/*
 * sort函数用于排序学生成绩和姓名，按照从高到低和姓名首字母排序
 * @param name 学生姓名
 * @param score 学生成绩
 * @param n 学生数
 */
void sort(char name[][50], int score[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (score[j] < score[j + 1] || (score[j] == score[j + 1] && strcmp(name[j], name[j + 1]) > 0))
            {
                int ts = score[j];
                score[j] = score[j + 1];
                score[j + 1] = ts;

                char tn[50];
                strcpy(tn, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tn);
            }
        }
    }
}

/*
 * output函数用于输出学生姓名和成绩，按照从高到低和姓名首字母排序
 * @param name 学生姓名
 * @param score 学生成绩
 * @param n 学生数
 */
void output(char name[][50], int score[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %d\n", name[i], score[i]);
}


/*
 * scarchmethod函数用于二分查找，查找数组score中元素为a的元素，返回其下标
 * @param score 学生成绩
 * @param l 左边界
 * @param r 右边界
 * @param a 要查找的元素
 */
int scarchmethod(int score[], int l, int r, int a) {
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (score[m] == a)
            return m;
        if (score[m] < a)
            l = m+ 1;
        else
            r = m - 1;
    }
    return -1;
}


/*
 * search函数用于查找数组score中元素为a的学生姓名和成绩，并输出
 * @param name 学生姓名
 * @param score 学生成绩
 * @param n 学生数
 */
void search(char name[][50], int score[], int n) {
    int a;
    scanf("%d", &a);

    int tag = scarchmethod(score, 0, n - 1, a);
    if (tag == -1)
        printf("not found\n");
    else
    {
        while (tag >= 0 && score[tag] == a)
        {
            printf("%s %d\n", name[tag], score[tag]);
            tag--;
        }
        tag = scarchmethod(score, 0, n - 1, a) + 1;
        while (tag < n && score[tag] == a)
        {
            printf("%s %d\n", name[tag], score[tag]);
            tag++;
        }
    }
}


/*
 * main主函数用于实现菜单功能
 */
int main() {
    char name[100][50];
    int score[100];
    int n;
    int choose;

    do
    {
        scanf("%d", &choose);

        switch (choose)
        {
            case 1:
                input(name, score, &n);
                break;
            case 2:
                sort(name, score, n);
                break;
            case 3:
                output(name, score, n);
                break;
            case 4:
                search(name, score, n);
                break;
            default:
                break;
        }
    } while (choose != 0);

    return 0;
}
