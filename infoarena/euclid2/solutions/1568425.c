#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    if(b==0) return a;
    return cmmdc(b, a%b);
}

int main(void)
{
    FILE *in = fopen("euclid2.in", "rt");
    if(!in) return 1;
    FILE *out = fopen("euclid2.out", "wt");
    int a,b,n,i;
    fscanf(in, "%d", &n);

    for (i = 0; i < n; ++i) {
        fscanf(in, "%d%d", &a, &b);
        fprintf(out, "%d\n", cmmdc(a,b));
    }

    fclose(in);
    fclose(out);
    return 0;
}
