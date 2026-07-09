#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
    int t, a, b, r;
    in >> t;

    for(int i = 1; i <= t; i++) {
        in >> a >> b;

        r = a % b;
        while(r != 0) {
            a = b;
            b = r;
            r = a % b;
        }

        out << b << "\n";
    }

    return 0;
}
