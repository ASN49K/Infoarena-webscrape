#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int x, int y) {
    while (y) {
        int aux = x % y;
        x = y;
        y = aux;
    }

    return x;
}

int main() {
    int n, x, y;
    f>>n;

    for (int i = 1; i <= n; i++) {
        f>>x>>y;
        g<<cmmdc(x, y)<<'\n';
    }

    return 0;
}
