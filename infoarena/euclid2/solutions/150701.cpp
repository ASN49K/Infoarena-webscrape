#include <stdio.h>

long long euclid (long long x,long long y)
{
    while (x&&y)
        if (x<y) x=y%x; else y=x%y;
    return (x)?(x):(y);
}
int main ()
{
    long long n,m;
    fscanf(fopen("euclid2.in","r"),"%ld %ld",&n,&m);
    fprintf(fopen("euclid2.out","w"),"%ld\n",euclid(n,m));
    return 0;
}
