#include<stdio.h>
int cmmdc(int x,int y)
{
    int z;
    while(y)
    {
        z=y;
        y=x%y;
        x=z;
    }
    return x;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,i,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
