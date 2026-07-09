#include <stdio.h>

long long euclid (long long x,long long y)
{
    while (x&&y)
        if (x>y) x%=y; else y%=x;
    return (x)?(x):(y);
}
int main ()
{
    long long n,m;
    fscanf(fopen("euclid2.in","r"),"%lld %lld",&n,&m);
    fprintf(fopen("euclid2.out","w"),"%lld\n",euclid(n,m));
    return 0;
}
