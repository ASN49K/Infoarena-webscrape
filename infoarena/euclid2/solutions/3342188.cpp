#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
    int t;
    in >> t;
    while (t--) {
        int a, b;
        in >> a >> b;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        out << a << "\n";
    }
    return 0;
}
