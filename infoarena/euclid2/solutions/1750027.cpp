#include <fstream>

using namespace std;

int euclid(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int a, b, t;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> t;

    for (int i = 0; i < t; i++) {
        in >> a >> b;
        out << euclid(a, b) << "\n";
    }

    return 0;
}