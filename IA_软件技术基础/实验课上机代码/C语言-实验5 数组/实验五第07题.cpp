//!这道题用了AI，有时间重新思考

/*
 * 本关任务：编写一个C程序，要求采用模块化设计思想，将相关功能用函数实现，并提供菜单选项，每次程序运行结束后需通过功能0退出程序。
 * 该程序具有以下功能：
 * 1.输入n个学生的姓名和C语言课程的成绩；
 * 2.将成绩按从高到低的次序排序，姓名同时进行相应调整（成绩相同的按姓名首字母排序，首字母相同的按第二个字母排序，依次类推）；
 * 3.输出所有学生的姓名和C语言课程的成绩。
 */

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
    printf("Enter the number of students: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("Enter name and score for student %d: ", i + 1);
        scanf("%s %d", name[i], &score[i]);
    }
}

/*
 * sort函数用于排序学生成绩和姓名，按照从高到低和姓名首字母排序
 * @param name 学生姓名
 * @param score 学生成绩
 * @param n 学生数
 * @param ts 用于交换成绩的临时变量
 * @param tn 用于交换姓名的临时变量
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
    printf("\nSorted list of students:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", name[i], score[i]);
    }
}


/*
 * main主函数用于实现菜单功能
 * @param name 学生姓名
 * @param score 学生成绩
 * @param n 学生数
 * @param choose 选择
 */
int main() {
    char name[100][50];
    int score[100];
    int n;
    int choose;

    do
    {
        printf("\nMenu:\n");
        printf("1. Input students' names and scores\n");
        printf("2. Sort students by scores\n");
        printf("3. Print all students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choose != 0);

    return 0;
}
