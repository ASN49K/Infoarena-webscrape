#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define sz size()
#define pb push_back
const ll mod = 1e9 + 7;
int n, m, q;

int gcd(int x, int y){
    if(x==y) return x;
    if(x==1 || y==1) return 1;
    if(x>y) return gcd(x-y, y); else return gcd(y-x, x);
}

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>>q;
    for(int i=1; i<=q; i++){
        cin>>n>>m; cout<<gcd(n, m)<<'\n';
    }
}
