#include <bits/stdc++.h>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int n, i, a, b, r, T;
int main() {
    fin >> T;
    for (i = 1; i <= T; i++) {
        fin >> a >> b;
        fout << cmmdc(a, b) << endl;
        }

    return 0;
}
