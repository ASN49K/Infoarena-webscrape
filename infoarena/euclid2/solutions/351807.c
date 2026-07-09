#include <stdio.h>
#include <stdlib.h>

int cmmdc(int div, int divi) {
    if (divi == 0) return div;
    return cmmdc(divi, div % divi);
}

int main()
{
    FILE *fin, *fout;

    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");

    int t, i, a, b;

    fscanf(fin, "%d", &t);
    for (i = 0; i < t; i++) {
        fscanf(fin, "%d", &a);
        fscanf(fin, "%d", &b);
        fprintf(fout, "%d", cmmdc(a, b));
        printf("%d", cmmdc(a, b));
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
