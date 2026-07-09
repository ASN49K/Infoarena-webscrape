#include <bits/stdc++.h>
using namespace std;
#define Nmax 1050
int a[Nmax],b[Nmax];
int n,m;
int dp[Nmax][Nmax];
vector <int> V;

int main(void) {
 ifstream cin("cmlsc.in");
 ifstream cout("cmlsc.out");
 cin>>n>>m;
 for (int i=1;i<=n;++i) cin>>a[i];
 for (int i=1;i<=m;++i) cin>>b[i];
 memset(dp,0,sizeof dp);
 
 for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j) { 
        if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                   else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
 cout<<dp[n][m]<<"\n"; 
 for (int i=n,j=m;i>=1 && j>=1;)
    if (a[i]==b[j]) V.push_back(a[i]), --i,--j;
          else 
    if (dp[i-1][j] > dp[i][j-1]) --i;
          else --j;
 for (int i=V.size()-1;i>=0;--i)
   cout<<V[i]<<" ";
 return 0;
}



