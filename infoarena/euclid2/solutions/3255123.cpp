#include <bits/stdc++.h>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int main () {
    long long n, a, b;
    in >> n;
    for (int i = 0 ; i < n ; i++) {
        in >> a >> b;
        while (b) {
            long long r = a % b;
            a = b;
            b = r;
        }
        out << a;
    }
    return 0;
}