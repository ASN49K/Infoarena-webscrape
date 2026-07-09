#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;

    int a, b;

    ifstream in;
    in.open("euclid2.in");

    ofstream out;
    out.open("euclid2.out");

    in >> n;

    for (int i = 0; i < n; ++i) {
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }

    in.close();
    out.close();

    return 0;
}