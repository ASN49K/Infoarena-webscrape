#include<stdio.h>

int cmmdc( unsigned a, unsigned b)
{
    if(!b) return a;
    else   return cmmdc(b, a%b);
}


int main()
{
    unsigned a, b, n = 0;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);   

    scanf("%d", &n);    

    for(unsigned i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a,b));
    }
}
