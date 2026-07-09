#include <bits/stdc++.h>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2out");

int main() {
    int n, a, b, r;

    fin >> n;

    for(int i = 0; i < n; i++) {
        fin >> a >> b;

        r = a % b;

        while(r) {
            a = b;
            b = r;
            r = a % b;
        }

        fout << b << '\n';
    }

    return 0;
}
