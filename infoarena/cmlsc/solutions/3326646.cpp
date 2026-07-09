#include <bits/stdc++.h>
using namespace std;
int a[2005];
int b[2005];
int dp[2005][2005];
int previ[2005][2005];
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
    int ras=0, pozi;
    for(int i=1; i<=n; i++)
    {
        int max1=0, poz=0;
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=max1+1;
                previ[i][j]=poz;
            }
            else
            {
                previ[i][j]=previ[i-1][j];
                dp[i][j]=dp[i-1][j];
            }
            if(dp[i-1][j]>max1)
            {
                max1=dp[i-1][j];
                poz=j;
            }
            if(dp[i][j]>ras)
            {
                ras=dp[i][j];
                pozi=j;
            }
        }
    }
    cout << ras << '\n';
    int cnt=0, val=n;
    while(pozi!=0)
    {
        aux[++cnt]=pozi;
        pozi=previ[val][pozi];
        val--;
    }
    for(int i=cnt; i>=1; i--)
    {
        if(aux[i]!=aux[i-1])
            cout << b[aux[i]] << ' ';
    }
    return 0;
}
