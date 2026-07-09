#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int cmmdc(int a, int b)
{
    if (a==0)
        return b;
    if (b==0)
        return a;
    if(a==b)
        return a;
    if(a<b)
    {
        b=b%a;
        return cmmdc(a,b);
    }
    else
        {
            a=a%b;
            return cmmdc(a,b);
        }
}

int main()
{
    FILE *in, *out;
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");
    int tests;
    fscanf(in, "%d", &tests);
    for (int i = 1; i <= tests; i++) {
        int a, b;
        fscanf(in, "%d %d", &a, &b);
        fprintf(out, "%d\n", gcd(a, b));
    }
    fclose(in);
    fclose(out);
    return 0;
}
