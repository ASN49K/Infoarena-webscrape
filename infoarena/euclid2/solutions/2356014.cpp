#include<bits/stdc++.h>

using namespace std;

int n,a,b;

int gcd(int a, int b) {
    if (!b) return a;
    else return gcd(b, a%b);
}

int main() {
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>>n;
    while (n--) {
        cin>>a>>b;
        cout<<gcd(a,b)<<'\n';
    }

    return 0;
}
