#include <stdio.h>

long int euclid (long int x,long int y)
{
    while (x&&y)
        if (x<y) x=y%x; else y=x%y;
    return (x)?(x):(y);
}
int main ()
{
    long int n,m;
    fscanf(fopen("euclid2.in","r"),"%ld %ld",&n,&m);
    fprintf(fopen("euclid2.out","w"),"%ld\n",euclid(n,m));
    return 0;
}
