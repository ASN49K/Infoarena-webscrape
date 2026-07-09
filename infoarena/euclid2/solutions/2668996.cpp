#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void citire() {
    int n; cin >> n;

    while (n) {
        --n;
        int x, y;
        cin >> x >> y;
        cout << cmmdc(x, y) << '\n';
    }
}

int main() {
    citire();
    return 0;
}