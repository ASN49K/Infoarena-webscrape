#include<stdio.h>
int a,b,div,n;
int cmmdc(int x,int y)
{
    int r;
    while(x%y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return y;
}
int main ()
{
    int i;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        div=cmmdc(a,b);
        printf("%d\n",div);
    }
    return 0;
}
