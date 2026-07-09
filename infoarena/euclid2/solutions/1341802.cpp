#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
int a, b, t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    cin>>a>>b;
    cout<<__gcd(a, b)<<'\n';

    }

    return 0;
}
