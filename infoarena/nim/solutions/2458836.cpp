#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,nr,n,i,j,s;
    scanf("%d",&t);
    for (i=1; i<=t; i++)
    {
        scanf("%d",&n);
        s=0;
        for (j=1; j<=n; j++)
        {
            scanf("%d",&nr);
            s=s^nr;
        }
        if (s)
            printf("DA");
        else
            printf("NU");
        printf("\n");
    }
    return 0;
}
