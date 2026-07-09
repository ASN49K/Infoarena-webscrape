#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int T;
    for (fin >> T; T; --T) {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << endl;
    }
}

int main() {
    solve();
    return 0;
}