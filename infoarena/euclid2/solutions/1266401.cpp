#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
    int t, x, y, r;
    in >> t;

    for(int i = 1; i <= t; i++) {
        in >> x >> y;

        r = x % y;
        while(r != 0) {
            x = y;
            y = r;
            r = x % y;
        }

        out << y << "\n";
    }

    return 0;
}
