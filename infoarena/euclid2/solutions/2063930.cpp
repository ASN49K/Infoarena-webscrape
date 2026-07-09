#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int t, a, b, res;

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> t;
    for ( ; t > 0; t--) {
        in >> a >> b;

        while (b != 0) {
            res = b;
            b = a % b;
            a = res;
        }

        out << res << '\n';
    }

    return 0;
}
