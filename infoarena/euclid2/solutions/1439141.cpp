//001
#include <cstdio>

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    FILE* fi = fopen("fractal.in", "rt");
    FILE* fo = fopen("fractal.out", "wt");

    long totaltest;
    fscanf(fi, "%ld", &totaltest);
    for (long test = 1; test <= totaltest; test++) {
        long a, b;
        fscanf(fi, "%ld%ld", &a, &b);
        fprintf(fo, "%ld\n", gcd(a, b));
    }

    return 0;
}
