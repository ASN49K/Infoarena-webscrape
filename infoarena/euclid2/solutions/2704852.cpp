#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t, a, b;

int gcd(int a, int b) {
    int aux = 0;

    while (b != 0) {
        if (b > a) {
            swap(a, b);
        }

        aux = a;
        a = b;
        b = aux % b;    
    }

    return a;
}

int main() {
    in >> t;
    
    while (t--) {
        in >> a >> b;
        out << gcd(a, b) << '\n';
    }

    return 0;
}