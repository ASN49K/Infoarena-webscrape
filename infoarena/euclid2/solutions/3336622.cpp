#include <fstream>
#include <cstdint>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

std::int32_t gcd(std::int32_t a, std::int32_t b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::int32_t T;
    std::int32_t a, b;

    in >> T;
    while(T--) {
        in >> a >> b;
        out << gcd(a, b) << '\n';
    }
    return 0;
}