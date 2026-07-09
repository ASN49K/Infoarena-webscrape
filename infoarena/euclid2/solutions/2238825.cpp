#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<__gcd(a,b)<<"\n";
    }
    return 0;
}
/**

**/
