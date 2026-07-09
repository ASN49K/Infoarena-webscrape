#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");
int t, n, a, rasp;

int main() {
    fin >> t;
    while(t--) {
        fin >> n;
        rasp = 0;
        while(n--) {
            fin >> a;
            rasp ^= a;
        }
        if(rasp != 0) fout << "DA\n";
        else          fout << "NU\n";
    }

    return 0;
}
