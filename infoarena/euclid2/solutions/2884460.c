#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    FILE *in, *out;
    in = fopen("euclid2.in","r");
    out = fopen("euclid2.out", "w");
    int t,x,y,v[100001];
    fscanf(in, "%d", &t);
    for(int i = 1; i <= t; i++)
    {
        fscanf(in, "%d %d", &x, &y);
        v[i] = cmmdc(x,y);
    }
    for(int i = 1; i <= t; i++)
    {
        fprintf(out, "%d\n", v[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}
