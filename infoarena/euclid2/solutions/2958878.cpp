#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

static inline int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int T, a, b;

    fin >> T;
    for (; T; --T) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
