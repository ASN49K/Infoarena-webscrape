#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

const int NMAX = 1e5 + 30;
const int INF = 0x3f3f3f3f;

int t, a, b;

void read()
{
    in >> t;
}

int euclid(int a, int b)
{
    if (b==0) return a; //ultimul rest e 0, returnam penultimul rest
    return euclid(b, a%b);
}

void solve()
{  
    while (t--)
        in>>a>>b, out<<euclid(a, b)<<'\n'; 
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    read();
    solve();

    return 0;
}