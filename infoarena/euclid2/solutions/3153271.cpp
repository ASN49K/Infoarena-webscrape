#include <fstream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int tests;
    fin >> tests;
    while (tests-- > 0) {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}