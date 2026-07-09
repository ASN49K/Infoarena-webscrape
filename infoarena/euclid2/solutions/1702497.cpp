#include<stdio.h>
using namespace std;
int main ()
{
    FILE *in, *out;
    in = fopen ("euclid2.in", "r");
    out = fopen ("euclid2.out", "w");
    int n;
    fscanf (in, "%d", &n);
    int a, b, i, r;
    for(i = 1; i <= n; i++)
    {
        fscanf(in, "%d%d", &a, &b);
        r = 1;
        while (r != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(out, "%d\n", a);
    }

    return 0;
}
