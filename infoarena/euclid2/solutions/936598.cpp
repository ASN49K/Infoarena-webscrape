#include<stdio.h>
int n,a,b,x;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for( ; n; --n)
    {
        scanf("%d%d",&a,&b);
        while(b)
        {
            x=b;
            b=a%b;
            a=x;
        }
        printf("%d\n",x);
    }
    return 0;
}
