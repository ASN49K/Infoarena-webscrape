#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;

int main() {
    in.tie(0);
    ios_base::sync_with_stdio(0);

    in >> t;
    while(t--){
        int a, b;
        in >> a >> b;
        out << __gcd(a,b) << '\n';
    }

    return 0;
}
