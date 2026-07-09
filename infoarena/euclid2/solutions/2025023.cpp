#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b) {

    int r;

    while (b) {

        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    int T, a, b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in >> T;

    for (int i = 1; i <= T; ++i) {

        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }

    in.close();
    out.close();

    return 0;
}
