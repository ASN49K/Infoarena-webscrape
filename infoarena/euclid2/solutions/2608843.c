#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
    if (b == 0) {
        return a;
    } 

    return cmmdc(b, a % b);
}


int main() {
    int T;
    int a, b;

    FILE *f = fopen("euclid2.in", "r");
    FILE *g = fopen("euclid2.out", "w");
    fscanf(f, "%d", &T);
    printf("%d\n", T);

    for (int i = 0; i < T; i++) {
        fscanf(f, "%d %d", &a, &b);
        printf("%d %d\n", a, b);
        fprintf(g, "%d\n", cmmdc(a, b));
    }

    fclose(f);
    fclose(g);

    return 0;
}