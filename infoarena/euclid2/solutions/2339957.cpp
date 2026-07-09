#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const mod=1000000007;
ll const md=998244353;
ll mypowr(ll a,ll b) {ll res=1;a%=mod; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll mypow(ll a,ll b) {ll res=1;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ifstream in("euclid2.in");
ofstream out("euclid2.out");
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second



int main()
{   cout<<fixed<<setprecision(12);
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    in>>n;
    while(n--){
        ll x,y;in>>x>>y;
        out<<__gcd(x,y)<<'\n';
    }






    return 0;
}
