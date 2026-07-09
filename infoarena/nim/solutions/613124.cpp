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
            printf("DA\n");
        }
        else
        {
            printf("NU\n");
        }
    }
    return 0;
}
