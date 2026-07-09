#include <cstdio>
using namespace std;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int main() {

    FILE *fin, *fout;
    fin = fopen("euclid2.in", "r");
    fout = fopen("euclid2.out", "w");

    int n, a, b;
    fscanf(fin, "%d", &n);
    for(int i=1; i<=n; i++) {
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d\n", gcd(a, b));
    }

    return 0;
}
