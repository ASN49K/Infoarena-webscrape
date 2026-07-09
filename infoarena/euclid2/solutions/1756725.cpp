
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
    long t, a, b;
    in >> t;
    for (long i = 0; i < t; i++) {
        in >> a >> b;
        while (a != 0 && b != 0)
            if (a > b)
                a %= b;
            else
                b %= a;
        out << a + b << '\n';
    }
    return 0;
}
