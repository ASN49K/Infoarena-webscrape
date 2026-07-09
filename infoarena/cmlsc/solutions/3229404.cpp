#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll a[1025],b[1025],dp[1025][1025];
int main(){
  //freopen("cmlsc.in","r",stdin);freopen("cmlsc.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,i,j;
  cin>>n>>m;
  for(i=1;i<=n;i++)cin>>a[i];
  for(i=1;i<=m;i++)cin>>b[i];
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
       dp[i][j]=max({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]+(a[i]==b[j])});
    }
  }
  cout<<dp[n][m]<<'\n';
  i=n;j=m;
  vector<ll>rez;
  while(i!=0&&j!=0){
    if(dp[i][j]==dp[i-1][j-1]+(a[i]==b[j])&&a[i]==b[j]){
      rez.pb(a[i]);
      i--,j--;
    }
    else if(dp[i][j]==dp[i-1][j])i--;
    else j--;
  }
  reverse(all(rez));
  for(ll x:rez)cout<<x<<' ';
  return 0;
}
