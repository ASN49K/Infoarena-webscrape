#include <fstream>
using namespace std;

int euclid (int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n, i, a, b;
    ofstream g("euclid2.out");
    ifstream f("euclid2.in");
    f >> n;
    for (i = 1; i <= n; i++) {
        f >> a >> b;
        g << euclid(a, b) << '\n';
    }
    f.close();
    g.close();
    return 0;
}