#include <stdio.h>

using namespace std;

FILE *fin = fopen("euclid2.in", "r");
FILE *fout = fopen("euclid2.out", "w");

int N;

int cmmdc(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int i, j;
    int a, b;

    fscanf(fin, "%d", &N);
    for (i = 1; i <= N; i++) {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", cmmdc(a, b));
    }

    return 0;
}
