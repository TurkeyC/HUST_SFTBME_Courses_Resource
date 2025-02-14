#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE *fp;
    // if (argc != 2) {
    //     printf("Arguments error!\n");
    //     exit(-1);
    // }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s file!\n", argv[1]);
        exit(-1);
    }

    int ch, line = 1, count = 0;
    printf("%d ", line++);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
        if (ch == '\n') {
            if (++count == 5) {

                getchar();
                count = 0;
            }
            printf("%d ", line++);
        }
    }
    fclose(fp);
    return 0;
}