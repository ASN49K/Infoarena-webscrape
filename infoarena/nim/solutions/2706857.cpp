#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t;

void solve() {
    int n, i, sumaxor = 0, x;
    f >> n;
    for (i = 1; i <= n; i++) {
        f >> x;
        sumaxor ^= x;
    }
    if (sumaxor)
        g << "DA\n";
    else g << "NU\n";
}

int main() {
    f >> t;
    while (t--)
        solve();
    f.close();
    g.close();
    return 0;
}