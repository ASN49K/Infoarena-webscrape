#include <stdio.h>

unsigned int cmmdc(unsigned int a, unsigned int b) {
    unsigned int aux;

    if (a < b) {
        aux = a;
        a = b;
        b = aux;
    }

    while (a % b != 0) {
        if (a < b) {
            aux = a;
            a = b;
            b = aux;
        }

        a = a % b;
    }

    return b;
}

void main() {
    FILE* in  = fopen("euclid2.in", "rt");
    FILE* out = fopen("euclid2.out", "wt");

    int T, i;
    unsigned int a, b;

    fscanf(in, "%d", &T);

    for (i = 0; i < T; i++) {
        fscanf(in, "%d %d", &a, &b);
        fprintf(out, "%d\n", cmmdc(a, b));
    }

    fclose(in);
    fclose(out);
}

