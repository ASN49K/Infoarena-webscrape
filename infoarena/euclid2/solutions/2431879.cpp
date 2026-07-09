#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    ll a,b,n;
    ifstream cin;
    cin.open("euclid2.in");
    ofstream cout;
    cout.open("euclid2.out");
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a>>b;
        cout<<gcd(a,b)<<"\n";
    }

    return 0;
}
