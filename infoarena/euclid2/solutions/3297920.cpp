#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
int a, b;

// x*a + y*b = gcd(a, b)
// x1*b + y1*(a % b) = gcd(a, b)
// a % b = a + lower_bound(a / b) * b
// x1*b + y1*(a + lower_bound(a / b) * b) = gcd(a, b)
// y1*a + b*(x1 - y1*lower_bound(a/b)) = gcd(a, b)
// x = y1, y = (x1 - y1*lower_bound(a / b))

int ExtendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1 = 0, y1 = 0;
    int d = ExtendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = (x1 - y1 * (a / b));
    return d;
}

int main() {
    fin >> T;
    for (int i = 0; i < T; i++) {
        fin >> a >> b;
        int x, y;
        fout << ExtendedEuclid(a, b, x, y) << "\n";
    }
    return 0;
}