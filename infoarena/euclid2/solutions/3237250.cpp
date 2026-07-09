#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a, b, n;

int cmmdc(int n, int m) {

    while (m != 0) {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main() {
    
    f >> n;
    for (int i = 0; i < n; i++) {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
}