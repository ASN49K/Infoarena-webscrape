#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b, T;
    cin >> T;

    for(int t = 0; t < T; ++t) {
        cin >> a >> b;
        cout << gcd(a, b);
    }
}
