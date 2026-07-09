#include <iostream>
#include <cstdio>

using namespace std;

FILE* fin = fopen("euclid2.in", "r");
FILE* fout = fopen("euclid2.out", "w");

int main()
{
    int a, b, t, i, r;

    fscanf(fin, "%d", &t);

    for (i = 0; i < t; ++i) {
        fscanf(fin, "%d %d", &a, &b);

        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(fout, "%d\n", a);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
