#include <algorithm>
#include <fstream>

using namespace std;

int n, a, b;

int gcd(int a, int b) {
    if (b)
        return gcd(b, a % b);
    return a;
}

int main() {
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
    }

    return 0;
}

