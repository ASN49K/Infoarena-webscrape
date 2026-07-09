#include <cstdio>

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

auto fin = fopen("euclid2.in", "r");
auto fout = fopen("euclid2.out", "w");

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