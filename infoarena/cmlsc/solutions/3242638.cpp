#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define pb push_back 

int main() 
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m; cin>>n>>m;
    vi a(n+1); vi b(m+1);
    int dp[1028][1028];
    for(int i = 1; i <= n; i++)
      cin>>a[i];
    for(int j = 1; j <= m; j++)
      cin>>b[j];
    for(int i = 1; i <= n; i++)
      {
      for(int j = 1; j <= m; j++)
        {
          if(a[i] == b[j])
              dp[i][j] = 1+ dp[i-1][j-1];
          else 
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
      }
    cout<<dp[n][m]<<'\n';
    int i = n; int j = m;
    vi v;
    while(i > 0 && j > 0)
      {
        if(a[i] ==  b[j])
          {
            v.pb(a[i]);
            i--;
            j--;
          }
        else if(dp[i-1][j] > dp[i][j-1])
          i--;
        else
          j--;
      }
    reverse(v.begin(), v.end());
    for(auto it : v)
      cout<<it<<" ";

  }
