#include <iostream>
#include <fstream>
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

    int T;
    fin >> T;

    for (int i = 0; i < T; i++) {
        long long a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
