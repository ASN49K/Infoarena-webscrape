#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define cin fin
#define cout fout
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
const int N=2e5+5;

void solve()
{
    int n;
    cin>>n;
    int xo=0;
    for(int i=1;i<=n;++i) {int x;cin>>x;xo^=x;}
    cout<<(xo==0 ? "NU":"DA");
}
signed main()
{
    int t=1;cin>>t;
    while(t--) {solve();cout<<'\n';}
}
