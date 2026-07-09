#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n, a, b;
    fin >> n;
    while (n > 0) {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
        --n;
    }
}
