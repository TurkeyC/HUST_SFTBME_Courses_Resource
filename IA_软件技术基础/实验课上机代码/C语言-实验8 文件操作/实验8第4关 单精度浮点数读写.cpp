#include <stdio.h>

void WFtF(const char *f_name) {
    FILE *file = fopen(f_name, "wb");

    float floats[10];

    for (int i = 0; i < 10; i++)
        scanf("%f", &floats[i]);

    fwrite(floats, sizeof(float), 10, file);
    fclose(file);
}

void RaDFfF(const char *f_name) {
    FILE *file = fopen(f_name, "rb");

    float floats[10];
    fread(floats, sizeof(float), 10, file);
    fclose(file);

    unsigned char *ptr;
    for (int i = 0; i < 10; i++)
    {
        ptr = (unsigned char *)&floats[i];
        for (int j = sizeof(float) - 1; j >= 0; j--)
            for (int k = 7; k >= 0; k--)
                printf("%d", (ptr[j] >> k) & 1);

        printf("\n");
    }
}

int main() {
    const char *f_name = "float.dat";

    WFtF(f_name);
    RaDFfF(f_name);

    return 0;
}