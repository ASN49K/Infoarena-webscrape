#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b)
        return gcd(b, a % b);
    return a;
}

int main() {
    ifstream cin("euclid2.in");
    freopen("euclid2.out", "w", stdout);

    int n, a, b;

    for (cin >> n; n; n--) {
        cin >> a >> b;
        printf("%d\n", gcd(a, b));
    }

    return 0;
}

