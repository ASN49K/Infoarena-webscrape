#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    int aux;
    if(b<a)
    {
        aux = a;
        a = b;
        b = aux;
    }
    if(b%a == 0)
    {
        return a;
    }
    int d = a/2;
    while(d>=1)
    {
        if(a%d == 0 && b%d == 0)
        {
            return d;
        }
        d--;
    }
}
int main()
{
    FILE *r, *w;
    r=fopen("euclid2.in", "r");
    w=fopen("euclid2.out", "w");
    int a,b,i,n;
    fscanf(r,"%d", &n);
    for(i=0; i<n; i++)
    {
        fscanf(r,"%d%d", &a,&b);
        fprintf (w, "%d\n", cmmdc(a,b));
    }
    return 0;
}
