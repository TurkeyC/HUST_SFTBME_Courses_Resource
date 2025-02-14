#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*定义学生信息链表*/
struct Student {
    char stuid[20];
    char name[20];
    int score[4];
    struct Student *next;
};

/*用于排序*/
void sorts(struct Student **head) {
    if (*head == NULL) return;
    struct Student *end = NULL;
    int swap;
    do {
        swap = 0;
        struct Student **current = head;

        while ((*current)->next != end)
        {
            struct Student *next = (*current)->next;
            float a_cur = ((*current)->score[0] + (*current)->score[1] + (*current)->score[2] + (*current)->score[3]) / 4.0;
            float avg_next = (next->score[0] + next->score[1] + next->score[2] + next->score[3]) / 4.0;

            if (a_cur > avg_next)
            {
                (*current)->next = next->next;
                next->next = *current;
                *current = next;
                swap = 1;
            }

            current = &(*current)->next;
        }
        end = *current;
    } while (swap);
}


/*用于输入每个学生的各项信息*/
void input(struct Student **head) {
    struct Student *new_student = (struct Student *)malloc(sizeof(struct Student));
    struct Student *tail = *head;
    scanf("%s", new_student->stuid);
    scanf("%s", new_student->name);
    for (int i = 0; i < 4; i++)
        scanf("%d", &new_student->score[i]);
    new_student->next = NULL;
    if (*head == NULL)
        *head = new_student;
    else
    {
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = new_student;
    }
}

/*用于根据学生人数循环输入每个学生的各项信息*/
void cirinput(struct Student **head) {
    int num;
    scanf("%d", &num);
    for (int j = 0; j < num; j++)
        input(head);
}

/*用于输出每个学生的各项信息*/
void output(struct Student **head) {
    sorts(head);
    struct Student *current = *head;
    while (current != NULL)
    {
        printf("%s %s %d %d %d %d\n", current->stuid, current->name, current->score[0], current->score[1], current->score[2], current->score[3]);
        current = current->next;
    }
}

/*用于修改指定学生的指定数据项的内容*/
void change(struct Student **head) {
    char id[20];
    int choice, new_score;
    scanf("%s", id);
    struct Student *current = *head;
    while (current != NULL && strcmp(current->stuid, id) != 0)
        current = current->next;
    scanf("%d", &choice);
    scanf("%d", &new_score);
    current->score[choice - 1] = new_score;
}

/*用于统计每个学生的平均成绩（保留2位小数）*/
void aver(struct Student **head) {
    sorts(head);
    struct Student *current = *head;
    while (current != NULL)
    {
        float average = 0;
        for (int i = 0; i < 4; i++)
            average += current->score[i];
        average /= 4;
        printf("%s %s %.2f\n", current->stuid, current->name, average);
        current = current->next;
    }
}


/*用于输出各位学生的学号、姓名、4门课程的总成绩和平均成绩*/
void outall(struct Student **head) {
    sorts(head);
    struct Student *current = *head;
    while (current != NULL)
    {
        int total = 0;
        float average = 0;
        for (int i = 0; i < 4; i++)
            total += current->score[i];
        average = total / 4.0;
        printf("%s %s %d %.2f\n", current->stuid, current->name, total, average);
        current = current->next;
    }
}

/*创建转移表*/
typedef void (*swt)(struct Student **head);
swt fpt[] = {cirinput, output, change ,aver, outall};

int main() {
    struct Student *head = NULL;
    int cho;
    do {
        scanf("%d", &cho);
        if (cho >= 1 && cho <= 6)
            fpt[cho - 1](&head);
    } while (cho != 0);
    return 0;
}