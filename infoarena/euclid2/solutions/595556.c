#include <stdio.h>
#include <stdlib.h>

int n;
int cmmdc(int a,int b)
{
    int r;
    while(b > 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int i,a,b;
    freopen("euclid2.in","rt",stdin);
    freopen("euclid2.out","wt",stdout);

    scanf("%d",&n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }

    return 0;
}
