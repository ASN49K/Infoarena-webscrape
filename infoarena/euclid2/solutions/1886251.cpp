#include <fstream>

int gcd(int x, int y) {return y == 0 ? x : gcd(y, x % y);}

int main() {
    std::ifstream in {"euclid2.in"};
    std::ofstream out {"euclid2.out"};

    int T, x, y;

    in >> T;

    while (T--) {
        in >> x >> y;
        out << gcd(x, y) << '\n';
    }

    out.close();
    in.close();

    return 0;
}
