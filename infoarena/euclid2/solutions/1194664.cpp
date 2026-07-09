#include <stdio.h>

using namespace std;

FILE * in = fopen ("euclid2.in", "r");
FILE * out = fopen ("euclid2.out", "w");

int t, m, n;

int euclid(int m, int n)
{
    if(n==0) return m;
    return euclid(n, m%n);
}

int main()
{
    fscanf(in, "%d", &t);
    for(int i=0; i<t; i++)
    {
        fscanf(in, "%d %d", &m, &n);
        fprintf(out, "%d\n", euclid(m,n));
    }
    return 0;
}
