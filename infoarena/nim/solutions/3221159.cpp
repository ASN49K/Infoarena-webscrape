#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define chad char
#define mod 1'000'000'007
#define dim 100005
#define lim 1000000
#define mdim 1501
#define mult 2e9
#define maxx 200002
#define simaimult 1e17
#define NMAX 1505
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define pli pair<ll,int>
#define pil pair<int,ll>
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define nr_biti __builtin_popcount
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t;
int n,s;

void solve()
{
    fin >> n;

    s=0;

    for(int i=1; i<=n; i++)
    {
        int x;
        fin >> x;

        s=(s^x);
    }

    if(s)
        fout << "DA\n";
    else 
        fout << "NU\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr);
    fout.tie(nullptr);

    fin >> t;

    while(t--)
        solve();

    return 0;
} 