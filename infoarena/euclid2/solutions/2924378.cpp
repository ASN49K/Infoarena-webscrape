#include <bits/stdc++.h>
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}
void solve(){
    int a,b;
    cin >> a >> b;

}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
