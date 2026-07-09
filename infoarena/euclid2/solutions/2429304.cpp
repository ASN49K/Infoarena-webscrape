#include <fstream>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    if (!a) {
        return a;
    }

    return cmmdc(a % b , b);
}

int main() {
    int T, a, b;

    in >> T;

    for (int i = 0 ; i < T ; ++i) {
        in >> a >> b;
        out << cmmdc(a, b);
    }

    return 0;
}
