#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    int n;
    fin >> n;
    for (int i = 1, a, b; i <= n; ++i) {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }
}
