#include <stdio.h>

int cmmdc(int a, int b) {
    int r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    FILE * fin, * fout;
    int a, b, t, i;

    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");
    fscanf(fin, "%d", &t);
    for (int i = 0; i < t; i++) {
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d\n", cmmdc(a, b));
    }
    fclose(fin);
    fclose(fout);

    return 0;
}