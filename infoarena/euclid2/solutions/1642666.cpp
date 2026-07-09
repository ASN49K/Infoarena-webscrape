#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long cmmdc(long long a, long long b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void read() {
    int n;
    f>>n;
    for (int i=1;i<=n;i++) {
        long long a, b;
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
}

int main() {

    read();

    f.close(); g.close();
    return 0;
}
