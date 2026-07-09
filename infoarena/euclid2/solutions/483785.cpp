#include <stdio.h>
using namespace std;

long long a, b;
int n, i;

long long cmmdc (long long a, long long b)
{
    long long r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main ()
{
    FILE *f = fopen ("euclid2.in","r");
    FILE *g = fopen ("euclid2.out","w");
    fscanf (f,"%d", &n);

    for (i=1; i<=n; ++i)
    {
        fscanf (f,"%lld %lld", &a, &b);
        fprintf (g, "%lld\n", cmmdc (a, b));
    }


    fclose (g);
    fclose (f);
    return 0;
}
