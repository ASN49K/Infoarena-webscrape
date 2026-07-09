#include <bits/stdc++.h>

using namespace std;

int n,m,a[1100],b[1100],dp[1100][1100],fin[1100],nfin;

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    for (int i=n,j=m; i;)
        if (a[i]==b[j])
        {
            fin[++nfin]=a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;

    cout<<nfin<<'\n';
    for (int i=nfin; i; i--)
        cout<<fin[i]<<" ";
    return 0;
}
