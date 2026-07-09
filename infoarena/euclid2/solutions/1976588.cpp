/*
    Keep It Simple!
*/

#include <fstream>

using namespace std;

long long gcd(long long a, long long b) {
    long long aux;
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
    long long a, b;

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
