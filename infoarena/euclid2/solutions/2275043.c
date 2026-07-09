#include <stdio.h>


int main()
{
    int n, a, b, i, r;
    FILE *in, *out;
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");
    fscanf(in, "%d", &n);
    for (i = 0;i < n;i++) {
        fscanf(in, "%d %d", &a, &b);
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(out, "%d\n", a);
    }
    return 0;
}
        
