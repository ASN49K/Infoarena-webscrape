#include<stdio.h>
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a,b,r;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d %d",&a,&b);
        r=1;
        while(r)
        {
            r=a%b;
            a=b;
            b=r;
        }
            printf("%d\n",a);
        t--;
    }
}
