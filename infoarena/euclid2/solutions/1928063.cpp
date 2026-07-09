#include <fstream>
using namespace std;
int gcd(int x1, int x2) {
    return (x2 == 0) ? x1 : gcd(x2, x1%x2);
}
int main() {
    ifstream fi("euclid2.in");
    ofstream fo("euclid2.out");
    int q;
    fi >> q;
    for (int i = 1; i <= q; i++) {
        int x1, x2;
        fi >> x1 >> x2;
        fo << gcd(x1, x2) << '\n';
    }
    return 0;
}
