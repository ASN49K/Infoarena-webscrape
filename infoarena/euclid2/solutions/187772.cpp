#include<stdio.h>
#define DIM 101
int a,b,q,n;
int main ()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
                     scanf("%d%d",&a,&b);
                     while(b)
                     {
                             q=a%b;
                             a=b;
                             b=q;
                     }
                     printf("%d\n",a);
    }
    return 0;
}
