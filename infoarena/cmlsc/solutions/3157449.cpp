#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> cmlsc(vector<ll> &a,vector<ll>&b)
{
    vector<vector<ll>> dp(a.size());
    ll i,j;
    for(i=0;i<a.size();i++)
    {
        dp[i].resize(b.size());
        for(j=0;j<b.size();j++)
        {
            dp[i][j]=(a[i]==b[j]);
            if(i>0&&j>0)dp[i][j]+=dp[i-1][j-1];
            if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
    vector<ll> rez;
    i=a.size()-1;
    j=b.size()-1;
    while(i>0||j>0)
    {
        while(i>0&&dp[i-1][j]==dp[i][j])i--;
        while(j>0&&dp[i][j-1]==dp[i][j])j--;
        if(a[i]==b[j])
        rez.push_back(a[i]);
        i--,j--;
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
