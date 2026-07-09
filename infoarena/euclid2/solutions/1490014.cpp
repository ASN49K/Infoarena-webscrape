#include <fstream>

int gcd(int x, int y) {return 0 == y ? x : gcd(y, x % y);}

int main() {
    int T, x, y;
    std::ifstream in{"euclid2.in"};
    std::ofstream out{"euclid2.out"};

    in >> T;
    while (T--) {
        in >> x >> y;
        out << gcd(x, y) << '\n';
    }

    return 0; 
}
