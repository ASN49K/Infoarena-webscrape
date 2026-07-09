#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a,b;
ll GCD(ll u, ll v) {
    while ( v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main() {
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
fin>>n;
for (ll i=1;i<=n;i++)
{
    fin>>a>>b;
    fout<<GCD(a,b)<<'\n';
}
fin.close();
fout.close();
    return 0;
}
