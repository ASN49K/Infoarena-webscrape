#include <bits/stdc++.h>
using namespace std;
#define mod               1000000007
#define ll                 long long 
#define all(v)             v.begin(), v.end()
#define fr(n)              for(ll i=0;i<n;++i)
#define ctz(x)             __builtin_ctz(x)
#define clz(x)             __builtin_clz(x)
#define pcount(x)          __builtin_popcountll(x)
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define cin fin
#define cout fout
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

ll dc(ll i, ll j){
    if(j==0) return i;
    else return dc(j, i%j);
    
}

void solve(){
    ll n, m;cin>>n>>m;
    cout<<dc(n, m);
    
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;cin>>t;while(t--){solve();cout<<"\n";}
}