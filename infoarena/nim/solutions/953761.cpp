#include<stdio.h>
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int n,i,s=0,x,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            s=s^x;
        }
        if(s==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
