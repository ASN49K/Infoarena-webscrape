#include <stdio.h>

int main() {
    long int t, a, b, r;
    FILE *in = fopen("euclid2.in", "r");
    FILE *out = fopen("euclid2.out", "w");
    fscanf(in, "%ld", &t);
    for (long int i = 0; i < t; i++) {
        fscanf(in, "%ld%ld", &a, &b);
        while (a != b) {
            if (a > b) a = a - b;
            if (b > a) b = b - a;
        };
        fprintf(out, "%ld\n", a);
    };
    fclose(out);
    fclose(in);
    return 0;
};