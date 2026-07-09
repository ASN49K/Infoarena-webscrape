#include<stdio.h>
int n,t,x,S;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        scanf("%d",&n);
        S=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&x);
            S=(S^x);
        }
        if(S==0)
            printf("NU\n");
        else
            printf("DA\n");

    }
    return 0;
}
