#include <stdio.h>

int main()
{
    int n, x, y, r, i;
    FILE *in, *out;
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");

    fscanf(in, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(in, "%d %d", &x, &y);

        do {
            r = x % y;
            x = y;
            y = r;
        } while (y != 0);

        fprintf(out, "%d\n", x);
    }
    
    fclose(in);
    fclose(out);
    return 0;
}