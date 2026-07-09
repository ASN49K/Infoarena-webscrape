#include <iostream>
#include <fstream>
std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");
int cmmdc(int a, int b) {
    if (!b) return a;
    return cmmdc(b, a % b);
}
int main() {

    int nr;
    f >> nr;

    int a, b;
    for (int i = 0; i < nr; i++) {
        f >> a >> b;
        g << cmmdc(a,b) << '\n';
    }

    return 0;
}
