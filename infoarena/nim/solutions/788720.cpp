#include <cstdio>

int t,n,s,x;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n);
            s=0;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&x);
                s^=x;
            }
            if(s)printf("DA\n"); else printf("NU\n");
        }
    return 0;
}

