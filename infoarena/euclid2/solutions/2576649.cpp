#include <fstream>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int T, x, y;
    in >> T;
    while (T--) {
        in >> x >> y;
        out << cmmdc(x, y) << '\n';
    }

    return 0;
}