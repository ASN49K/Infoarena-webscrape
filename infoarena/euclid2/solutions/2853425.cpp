#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF=1e9+7;
const ll INFF=1e18+7;
#define nl '\n'
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char* x) { cout << '\"' << x << '\"'; }
void __print(const string& x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V>& x) { cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}'; }
template<typename T>
void __print(const T& x) { int f = 0; cout << '{'; for (auto& i : x) cout << (f++ ? "," : ""), __print(i); cout << "}"; }
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cout << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int cmmdc(int x, int y){
    if(y==0) return x;
    return(y,y%x);
}

void solve()
{
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int x,y;
        cin>>x>>y;
        cout<<cmmdc(x,y)<<nl;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // int t;
    // cin >> t;
    for(int tt=1; tt<=t; tt++){
        // cout<<"#Case "<<t<<nl;
        solve();
    }
    return 0;
}