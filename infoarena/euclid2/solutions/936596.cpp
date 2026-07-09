#include<stdio.h>
int n,a,b;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for( ; n; --n)
    {
        scanf("%d%d",&a,&b);
        while(a!=b)
            if(a>b)
                a-=b;
            else
                b-=a;
        printf("%d\n",a);
    }
    return 0;
}
