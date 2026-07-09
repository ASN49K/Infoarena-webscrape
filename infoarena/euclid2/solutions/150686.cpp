#include <stdio.h>

int euclid (int x,int y)
{
    while (x&&y)
        if (x<y) x=y%x; else y=x%y;
    return (x)?(x):(y);
}
int main ()
{
    int n,m;
    fscanf(fopen("euclid2.in","r"),"%d %d",&n,&m);
    fprintf(fopen("euclid2.out","w"),"%d\n",euclid(n,m));
    return 0;
}
