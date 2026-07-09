#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a, b;
    int n;
    in >> n;

    int res;
    for (int i = 0; i < n; i++) {
        in >> a >> b;
        res = gcd(a, b);
        out << res << '\n';
    }

    in.close();
    out.close();
    return 0;
}
