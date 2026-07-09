#include <bits/stdc++.h>
#define ll long long int
#define double long double
#define pb push_back
#define endl '\n'
#define er erase
#define sz size
#define in insert
#define mp make_pair
#define f first
//#define s second
#define mod 1000000007
using namespace std;

ll m, n, dp[1030][1030], ans[1030];
vector<ll> a, b;

int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>m>>n;
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        a.pb(x);
    }
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        b.pb(x);
    }
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(a[i]==b[j]){dp[i][j]=dp[i-1][j-1]+1;}
            else{dp[i][j]=max(dp[i][j-1], dp[i-1][j]);}
        }
    }
    ll u=m-1, v=n-1, x=dp[m-1][n-1];
    while(x)
    {
        if(a[u]==b[v]){ans[x]=a[u];u--;v--;x--;}
        else{if(dp[u][v-1]>dp[u-1][v]){v--;}else{u--;}}
    }
    cout<<dp[m-1][n-1]<<endl;
    for(ll i=1;i<=dp[m-1][n-1];i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
