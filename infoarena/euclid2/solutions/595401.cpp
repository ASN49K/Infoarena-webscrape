#include <stdio.h>

int main()
{
    int t=0,i=0,a=0,b=0;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for (i=0; i<t; ++i)
    {
            scanf("%d%d",&a,&b);
            while (a%b!=0 && b%a!=0)
            {
                a%=b;
                if (b%a==0) break;
                b%=a;
            }
            if (b%a==0) printf("%d\n",a);
            else printf("%d\n",b);
    }
    return 0;
}
