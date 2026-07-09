#include <fstream>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int cmmdc(int a, int b) {
    while (a && b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    if (a)
        return a;

    return b;
}

int main() {
    int nr = 0;
    in >> nr;

    for (int i = 0; i < nr; i++) {
        int a, b;

        in >> a >> b;

        out << cmmdc(a, b) << std::endl;
    }

    return 0;
}
