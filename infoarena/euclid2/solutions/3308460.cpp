#include <bits/stdc++.h>

#pragma GCC target("avx2")
//#define int long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
using namespace __gnu_pbds;
using namespace std;
//ofstream fout("date.out");
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
vector <pair<vector <int>,int>> v;
int a,b;
int euclid(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void solve()
{
    fin>>a>>b;
    fout<<euclid(a,b)<<'\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    fin>>t;
    while(t--)
        solve();
    return 0;
}
