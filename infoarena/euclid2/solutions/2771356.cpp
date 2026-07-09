#include <fstream>

#define SPACE " "
#define NL "\n"

using namespace std;

int euclid(int a, int b) {
    int M = max(a, b);
    int m = min(a, b);

    int r = M % m;

    while (r > 0) {
        M = m;
        m = r;
        r = M % m;
    }

    return m;
}

int main(void) {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int T, a, b;
    in >> T;

    for (int i = 0; i < T; i++) {
        in >> a >> b;
        out << euclid(a, b) << SPACE << NL;
    }

    return 0;
}
