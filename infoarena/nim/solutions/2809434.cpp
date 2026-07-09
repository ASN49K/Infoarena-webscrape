#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define double long double;
#define pb push_back
#define endl '\n'
#define er erase
#define sz size
#define in insert
#define mp make_pair
#define fs first
#define sc second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mod 1000000007
#define INF LONG_LONG_MAX

ll n, a[10005];

ifstream fin("nim.in");
ofstream fout("nim.out");

void solve()
{
    fin>>n;
    for(ll i=0;i<n;i++)
        fin>>a[i];
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans^=a[i];
    }
    if(ans==0){fout<<"NU"<<endl;}else{fout<<"DA"<<endl;}
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll tc=1;
    fin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
