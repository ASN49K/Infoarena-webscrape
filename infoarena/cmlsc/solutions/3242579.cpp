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
    vi a(n); vi b(m); stack<int> s;
    for(int i = 0; i < n; i++)
      cin>>a[i];
    for(int i = 0; i < m; i++)
      cin>>b[i];
    int dp[256][256] = {0};
    for(int i = n - 1; i >= 0; i--)
      {
      for(int j = m - 1; j>= 0; j--)
        {
          if(a[i] == b[j])
            {
            dp[i][j] = 1 + dp[i+1][j+1];
            s.push(a[i]);
            }
            
          else 
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
      }
      cout<<dp[0][0]<<'\n';
      while(!s.empty())
        {
          cout<<s.top()<<" ";
          s.pop();
        }
  }


