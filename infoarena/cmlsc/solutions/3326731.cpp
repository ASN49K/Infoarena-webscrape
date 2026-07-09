#include <bits/stdc++.h>
using namespace std;
int a[2005];
int b[2005];
int dp[2005][2005];
int aux[2005];
int main()
{
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];
    int  cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    int i=n, j=m;
    while(i>=1 || j>=1)
    {
        if(a[i]==b[j])
            aux[++cnt]=a[i], i--, j--;
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    for(int i=cnt; i>=1; i--)
        cout << aux[i] << ' ';
    return 0;
}