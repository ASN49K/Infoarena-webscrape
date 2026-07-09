#include <bits/stdc++.h>

using namespace std;

long long cmmdc(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int x;
    fin >> x;

    for (int i = 0; i < x; i++) {
        long long a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }

    return 0;
}