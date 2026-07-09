#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int eucl(int a, int b) {
    if (b == 0) return a;
    return eucl(b, a % b);
}

int main() {
    int a, b, T;
    fin >> T;
    for (int i = 1; i <= T; i++) {
        fin >> a >> b;
        fout << eucl(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}