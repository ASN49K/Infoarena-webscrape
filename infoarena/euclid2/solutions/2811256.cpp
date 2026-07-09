#include <iostream>
#include <fstream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a, b, t;
    fin >> t;
    for (int i = 1; i <= t; i++) {
        fin >> a >> b;
        fout << GCD(a, b) << '\n';
    }
    return 0;
}
