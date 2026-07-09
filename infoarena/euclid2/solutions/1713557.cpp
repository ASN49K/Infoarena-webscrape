#include <fstream>

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    std::ifstream in{"euclid2.in"};
    std::ofstream out{"euclid2.out"};

    int T, a, b;

    for (in >> T; T; --T) {
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }

    in.close();
    out.close();

    return 0;
}
