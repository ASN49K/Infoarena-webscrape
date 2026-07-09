#include <bits/stdc++.h>
using namespace std;

long long n, a, b, aux;
int f_cmmdc (int x, int y) {
    while (y) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        aux = f_cmmdc(a, b);
        cout << aux << endl;
    }
    return 0;
}