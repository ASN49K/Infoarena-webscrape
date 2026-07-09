#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t, a, b;

static inline int gcd(int a, int b) {
    while(b) {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }

    return 0;
}
