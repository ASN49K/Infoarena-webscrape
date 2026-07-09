#include <stdlib.h>
#include <stdio.h>

#define T 100000
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long tmp;

    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}
int main() {
    int t;
    unsigned long long a, b, tmp, tmpa, tmpb;
    int i;
    FILE *in, *out;

    in = fopen("euclid2.in", "r");
    if (in == NULL) {
        fprintf(stderr, "Failed to open euclid2.in");
        return -1;
    }

    out = fopen("euclid2.out", "w");
    if (out == NULL) {
        fprintf(stderr, "Failed to open euclid2.out");
        return -1;
    }

    fscanf(in, "%d", &t);

    for (i = 0; i < t; i++) {
        fscanf(in, "%llu %llu\n", &tmpa, &tmpb);
        a = max(tmpa, tmpb);
        b = min(tmpa, tmpb);
        fprintf(out, "%llu\n", gcd(a, b));
    }

    fclose(in);
    fclose(out);

    return 0;
}

