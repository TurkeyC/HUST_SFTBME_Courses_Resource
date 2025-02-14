#include <stdio.h>
#include <string.h>

int main(void) {
    char *(*copy_func)(char *, const char *) = strcpy;
    char *(*concat_func)(char *, const char *) = strcat;
    char *(*parse_func)(char *, const char *) = strtok;

    char a[80], b[80], *result;
    int choice;

    while (1) {
        do
        {scanf("%d", &choice);}
        while (choice < 1 || choice > 4);

        getchar();
        fgets(a, sizeof(a), stdin);
        a[strcspn(a, "\n")] = '\0';
        fgets(b, sizeof(b), stdin);
        b[strcspn(b, "\n")] = '\0';

        switch (choice) {
            case 1:result = copy_func(a, b);break;
            case 2:result = concat_func(a, b);break;
            case 3:result = parse_func(a, b);break;
            case 4:goto down;
        }
        printf("%s\n", result);
    }

    down:
        return 0;
}