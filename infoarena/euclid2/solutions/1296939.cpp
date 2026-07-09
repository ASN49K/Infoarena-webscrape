#include <stdio.h>

int cmmdc(int a, int b)
{
    if(a==b)
        return a;
    if(a<b)
    {
        b=b-a;
        return cmmdc(a,b);
    }
    else
        {
            a=a-b;
            return cmmdc(a,b);
        }
}

int main()
{
    FILE *in, *out;
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");
    int a, b;
    fscanf(in, "%d %d", &a, &b);
    fprintf(out, "%d\n", cmmdc(a, b));
    fclose(in);
    fclose(out);
    return 0;
}
