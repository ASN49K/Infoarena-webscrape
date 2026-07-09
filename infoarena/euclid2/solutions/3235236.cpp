#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin >> a >> b;
    cout << __gcd(a,b);
    cout<<"\n";
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}