/*
    Keep It Simple!
*/

#include <fstream>

using namespace std;

int gcd(int a, int b) {
    int aux;
    while (b) {
        aux = a%b;
        a = b;
        b = aux;
    }
    return a;
}

void Solve() {
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T;
    int a, b;

    f >> T;
    while (T--) {
        f >> a >> b;
        g << gcd(a,b) << '\n';
    }
}

int main() {
    Solve();
    return 0;
}
