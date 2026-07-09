#include <bits/stdc++.h>
#define pb push_back
//#define int long long
using namespace std;
const int N=1e5+5;
signed main()
{
    ifstream cin("euclid2.in");ofstream cout("euclid2.out");
    int t;cin>>t;
    while(t--)
    {
        int a,b;cin>>a>>b;
        cout<<__gcd(a,b)<<'\n';
    }
}
