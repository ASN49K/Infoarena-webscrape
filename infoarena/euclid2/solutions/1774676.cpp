#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int gcd(int a, int b) {
    return (!b) ? a : gcd(b, a % b);
}

int main() {
    fin >> T;
    while(T--) {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }

    return 0;
}
