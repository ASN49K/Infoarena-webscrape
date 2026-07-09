#include <stdio.h>
int a,b;
int euclid (int a, int b)
{
    int r;
    do
    {
        r=a%b;
        a=b;
        b=r;
    }
    while (r);
    return a;
}
int main ()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    int k;
    scanf ("%d%d",&a,&b);
    k=euclid (a,b);
    printf ("%d",k);
    return 0;
}
