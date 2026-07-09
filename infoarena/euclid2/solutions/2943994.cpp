#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T;
    while(T--) {
        int a, b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}
