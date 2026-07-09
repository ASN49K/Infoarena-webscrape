#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a < b) swap(a, b);
    while(b){
        int t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n;
    cin >> n;
    int unu[n], doi[n];
    for (int i = 0; i < n; i++) cin >> unu[i] >> doi[i];
    for (int i = 0; i < n; i++) cout << gcd(unu[i], doi[i]) << endl;
    return 0;
}