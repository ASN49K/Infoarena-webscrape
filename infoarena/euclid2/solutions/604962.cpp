#include <stdio.h>

int cmmdc(int a, int b)
{
    if(!b) return(a);
    return cmmdc(b, a%b);
}

int main()
{
    int p,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &p);
    for(int i=1;i<=p;i++)
    {
         scanf("%d %d", &a, &b);
         printf("%d\n", cmmdc(a, b));
    }
}
