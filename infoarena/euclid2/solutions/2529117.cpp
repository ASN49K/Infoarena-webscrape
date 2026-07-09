#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;

int cmmdc(int a, int b) {
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

int main() {
    in >> t;
    while (t --) {
        int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }

    return 0;
}
