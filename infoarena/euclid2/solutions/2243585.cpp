#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    if (!b)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    int test, a, b;
    in >> test;
    while (test --) {
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }
    return 0;
}
