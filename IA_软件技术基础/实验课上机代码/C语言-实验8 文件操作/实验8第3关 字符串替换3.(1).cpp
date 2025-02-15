#include <stdio.h>
#include <string.h>

void ref(const char *fname, const char *tar, const char *replace) {
    FILE *input = fopen(fname, "r");

    FILE *output = fopen("out.txt", "w");

    char buf[1000];
    while (fgets(buf, sizeof(buf), input) != NULL) {
        char *pos;
        while ((pos = strstr(buf, tar)) != NULL) {
            *pos = '\0';
            fprintf(output, "%s%s", buf, replace);
            strcpy(buf, pos + strlen(tar));
        }
        fprintf(output, "%s", buf);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {

    const char *fname = argv[1];
    const char *tar = argv[2];
    const char *replace = argv[3];

    ref(fname, tar, replace);

    return 0;

}