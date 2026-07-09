#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define fs first
#define sd second

using namespace std;

const string fileName = "euclid2";
ifstream in(fileName + ".in");
ofstream out(fileName + ".out");

signed main() {
    int t; in >> t;
    while(t--) {
        int a, b; in >> a >> b;
        while(b != 0) {
            int aux = a;
            a = b;
            b = aux % b;
        }
        out << a << '\n';
    }
    return 0;
}
