#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    while(b) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int n, a, b;
int main() {
    in >> n;
    while(n--) {
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }

    in.close();
    out.close();
    return 0;
}
