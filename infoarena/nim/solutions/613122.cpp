#include<cstdio>

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    int n, t;
    scanf("%d",&t);
    for(;t;--t)
    {
        int s=0;
        scanf("%d",&n);
        for(;n;--n)
        {
            int x;
            scanf("%d",&x);
            s^=x;
        }
        if(s)
        {
            printf("NU\n");
        }
        else
        {
            printf("DA\n");
        }
    }
    return 0;
}
