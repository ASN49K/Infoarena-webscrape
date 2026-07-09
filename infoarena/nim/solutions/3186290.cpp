#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
int t, n, a, r;

int main() {
    fin >> t;
    while(t--) {
        fin >> n;
        r = 0;
        while(n--) {
            fin >> a;
            r ^= a;
        }
        if(r != 0) fout << "DA\n";
        else       fout << "NU\n";
    }

    return 0;
}
