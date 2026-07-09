#include<stdio.h>

int gcd(int a, int b) {
    int r;
    while (b) {
        r = b;
        b = a % r;
        a = r;
    }

    return a;
}

int main()
{
    FILE *f = fopen("euclid2.in", "r");
    FILE *g = fopen("euclid2.out", "w");
    int t, a, b;
    int i = 0;
    fscanf(f, "%d", &t);

    while (i < t) {
        fscanf(f,"%d %d", &a, &b);
        fprintf(g,"%d\n", gcd(a,b));
        i++;
    }

    fclose(f);
    fclose(g);

    return 0;
}

