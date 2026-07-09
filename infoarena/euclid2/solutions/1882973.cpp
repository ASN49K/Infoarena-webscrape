#include "stdc++.h"

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

FILE* fin = fopen("euclid2.in", "r");
FILE* fout = fopen("euclid2.out", "w");

int main() {
    int t;

    fscanf(fin, "%d", &t);
    while (t--) {
        int a, b;
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", gcd(a, b));
    }
    return 0;
}