#include <bits/stdc++.h>
using namespace std;

int a,b,t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<__gcd(a,b)<<"\n";
    }
    return 0;
}