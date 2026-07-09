#include <iostream>
#include <fstream>
using namespace std;

int main () {
    int i, n , a, b, r;
    ifstream in;
    ofstream out;
    in.open("euclid2.in");
    out.open("euclid2.out");
    in >> n;
    for (i = 0; i < n; i++) {
        in >> a >> b;
        r = 1;
        while (r != 0) {
            r = a % b;
            a = b;
            if (r != 0)
                b = r;
        }
        out << b << "\n";
    }
    in.close();
    out.close();
    return 0;
}
