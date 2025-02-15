#include <stdio.h>
#include <string.h>

int main(void) {
    char *(*copy_func)(char *, const char *) = strcpy;
    char *(*concat_func)(char *, const char *) = strcat;
    char *(*parse_func)(char *, const char *) = strtok;

    char a[100], b[100], *result;
    int choice;

    char *(*funcTable[4])(char *, const char *) = {strcpy, strcat, strtok};

    while (1) {
        do {
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        getchar();
        fgets(a, sizeof(a), stdin);
        a[strcspn(a, "\n")] = '\0';
        fgets(b, sizeof(b), stdin);
        b[strcspn(b, "\n")] = '\0';

        if(choice==4) return 0;
        result = funcTable[choice - 1](a, b);
        printf("%s\n", result);
    }
}