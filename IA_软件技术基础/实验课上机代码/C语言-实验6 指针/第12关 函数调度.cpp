#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void task0() { printf("task0 is called!\n"); }
void task1() { printf("task1 is called!\n"); }
void task2() { printf("task2 is called!\n"); }
void task3() { printf("task3 is called!\n"); }
void task4() { printf("task4 is called!\n"); }
void task5() { printf("task5 is called!\n"); }
void task6() { printf("task6 is called!\n"); }
void task7() { printf("task7 is called!\n"); }

void (*tasks[])() = {task0, task1, task2, task3, task4, task5, task6, task7};

void execute(void (**ta)(), int count) {
    for (int i = 0; i < count; i++) {
        ta[i]();
    }
}

void scheduler() {
    char str[100];
    scanf("%s", str);

    int len = strlen(str);
    void (**cho)() = (void(**)())malloc(len * sizeof(void (*)()));
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        int task_index = str[i] - '0';
        if (task_index >= 0 && task_index <= 7)
            cho[count++] = tasks[task_index];
    }
    execute(cho, count);
}

int main() {
    scheduler();
    return 0;
}