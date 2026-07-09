#include <bits/stdc++.h>
using namespace std;

inline int gcd (int a, int b) {return b?gcd(b, a%b):a;}
int main () {
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    ios::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    int n, x, y;
    for (fin >> n; n; n--) {
        fin >> x >> y;
        fout << gcd(x, y) << '\n';
    }
    return 0;
}
