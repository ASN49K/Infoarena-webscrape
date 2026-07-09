#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
#define cin fin
#define cout fout
int n,m,a[2025],b[2025],rez[2025],dp[2025][2025],cnt;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=m;i++)
        cin>>b[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    cout<<dp[n][m]<<'\n';

    while (n!=0 && m!=0)
    {
        if (a[n]==b[m])
        {
            rez[cnt]=a[n];
            n--,m--;
            cnt++;
        }
        else if (dp[n-1][m]>=dp[n][m-1]) n--;
        else m--;
    }
    for (int i=cnt-1;i>=0;i--)
        cout<<rez[i]<<' ';
    cout<<'\n';

    return 0;
}
