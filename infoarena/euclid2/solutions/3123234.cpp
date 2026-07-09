#include <iostream>
#include <cstdio>
using namespace std;

int tests, x, y;

int gcd(int x, int y) {
    int rem;
    while (y) {
        rem = x % y;
        x = y;
        y = rem;
    }
    return x;
}

int main()
{
    freopen("euclid.in", "r", stdin);
    freopen("euclid.out", "w", stdout);
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        cin >> x >> y;
        cout << gcd(x, y) << "\n";
    }
    return 0;
}