#include<cstdio>
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int xo=0,t,i,x,i1,n;
    scanf("%d",&t);
    for(i1=1;i1<=t;i1++)
        {
        xo=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            xo=xo^x;
            }
        if (xo==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
return 0;
}
