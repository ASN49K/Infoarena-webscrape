#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n;

unsigned long long x, y;

unsigned long long gcd (unsigned long long x, unsigned long long y) {
    long long aux;
    while (x % y) {
        aux = y;
        y = x % y;
        x = aux;
    }
    return y;
}

int main () {
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> x >> y;
        fout << gcd (x, y) << "\n";
    }
    return 0;
}
