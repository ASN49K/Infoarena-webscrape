#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T, A, B;

int cmmdc(int a, int b) {
    if(!b) return a;
    return cmmdc(b, a % b);
}

int main() {
    FILE *f1=fopen("euclid2.in", "r"), *f2=fopen("euclid2.out", "w");

    fscanf(f1, "%d\n", &T);
    while(T--) {
         fscanf(f1, "%d %d\n", &A, &B);

         fprintf(f2, "%d\n", cmmdc(A, B));
    }

    fclose(f1); fclose(f2);
    return 0;
}
