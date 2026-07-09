#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    FILE *in = fopen("euclid2.in", "r");
    FILE *out = fopen("euclid2.out", "w");

    int n, a, b, i, r;
    fscanf(in, "%d", &n);

    for (i=0; i<n; i++) {
        fscanf(in, "%d%d", &a, &b);

        while (b) {
            r = a%b;
            a = b;
            b = r;
        }

        fprintf(out, "%d\n", a);
    }

    fclose(in);
    fclose(out);
    return 0;
}
