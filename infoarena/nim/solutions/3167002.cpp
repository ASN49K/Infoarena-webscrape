#include <iostream>

using namespace std;

int main()
{
    FILE *fin, *fout;
    fin = fopen("nim.in", "r");
    fout = fopen("nim.out", "w");

    int t, n, xorsum, i, x;
    fscanf(fin, "%d", &t);
    while(t--) {
        fscanf(fin, "%d", &n);
        xorsum = 0;
        for(i = 0; i < n; i++) {
            fscanf(fin, "%d", &x);
            xorsum = xorsum ^ x;
        }
        if (xorsum == 0) {
            fprintf(fout, "NU\n");
        } else {
            fprintf(fout, "DA\n");
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}