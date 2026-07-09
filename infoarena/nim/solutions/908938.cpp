#include<stdio.h>
long t, ii, n, s, x, i;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%ld",&n);    s=0;
        for (i=1;i<=n;i++)
        {
            scanf("%ld",&x);
            s=s^x;
        }
        if (s>0)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
