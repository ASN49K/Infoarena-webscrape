#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int a, b;
    fin >> a >> b;
    fout << gcd(a, b) << '\n';
}

int main() {
    int t;

    fin >> t;
    for (; t; t--)
        solve();
    return 0;
}