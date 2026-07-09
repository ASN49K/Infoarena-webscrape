#include <bits/stdc++.h>

using namespace std;
ifstream ("euclid2.in");
ofstream ("euclid2.out");
int n, i, a, b, r;
unsigned long long S = 0;
int main() {
    cin >> T;
    for (i = 1; i <= T; i++) {
        cin >> a >> b;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        cout << b << "/n";

    return 0;
}
