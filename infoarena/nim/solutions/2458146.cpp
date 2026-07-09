#include <bits/stdc++.h>

int t,i,j,x,n,rez;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for (i=1; i<=t; i++)
    {
        scanf("%d",&n);
        rez=0;
        for (j=1; j<=n; j++)
        {
            scanf("%d",&x);
            rez=rez^x;
        }
        if (rez!=0) printf("DA\n");
            else printf("NU\n");
    }
    return 0;
}
