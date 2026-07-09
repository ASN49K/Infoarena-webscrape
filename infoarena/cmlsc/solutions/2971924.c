#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    short unsigned int n,m,bst=0;
    scanf("%hu",&n);
    scanf("%hu",&m);

    unsigned char v[1024],u[1024],sir[1024];
    unsigned char dp[1024][1024];

    for(int i=1; i<=n; i++)
        scanf("%hhu",&v[i]);

    for(int i=1; i<=m; i++)
        scanf("%hhu",&u[i]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(v[i]==u[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=(dp[i-1][j]>dp[i][j-1]) ? dp[i-1][j]:dp[i][j-1];
        }

    int i=n;
    int j=m;
    while(i>0 || j>0)
    {
        if(u[j]==v[i])
        {
            sir[bst]=v[i];
            bst++;
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
                j--;
            else i--;
        }
    }

    printf("%hu\n",bst);
    for(i=bst-1;i>=0;i--)
        printf("%hhu ",sir[i]);
    return 0;
}
