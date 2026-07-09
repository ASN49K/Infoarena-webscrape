#include <stdio.h>
int n,a,b;
int cmmdc(int a,int b)
{
     if (!a) return b;
     else return cmmdc(b%a,a);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for (;n>0;n--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
