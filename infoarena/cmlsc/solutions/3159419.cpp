#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T>T cmlsc(T &a,T&b)
{
    vector<vector<pair<ll,pll>>> dp(a.size());
    ll i,j;
    for(i=0;i<a.size();i++)
    {
        dp[i].resize(b.size());
        for(j=0;j<b.size();j++)
        {
            dp[i][j]={(a[i]==b[j]),{i,j}};
            if(i>0&&j>0)dp[i][j].first+=dp[i-1][j-1].first,dp[i][j].second=(a[i-1]==b[j-1]?make_pair(i-1,j-1):dp[i-1][j-1].second);
            if(i>0&&dp[i-1][j].first>dp[i][j].first)dp[i][j].first=dp[i-1][j].first,dp[i][j].second=(a[i-1]==b[j]?make_pair(i-1,j):dp[i-1][j].second);
            if(j>0&&dp[i][j-1].first>dp[i][j].first)dp[i][j].first=dp[i][j-1].first,dp[i][j].second=(a[i]==b[j-1]?make_pair(i,j-1):dp[i][j-1].second);
        }
    }
    T rez;
    pll aux={a.size()-1,b.size()-1};
    if(a.back()==b.back())rez.push_back(a.back());
    while(aux!=dp[aux.first][aux.second].second)
    {
        aux=dp[aux.first][aux.second].second;
        if(a[aux.first]==b[aux.second])rez.push_back(a[aux.first]);
    }
    reverse(rez.begin(),rez.end());
    return rez;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    ll n,m,i,j;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<m;i++)cin>>b[i];
    vector<ll> rez=cmlsc(a,b);
    cout<<rez.size()<<'\n';
    for(ll x:rez)cout<<x<<' ';
	return 0;
}
