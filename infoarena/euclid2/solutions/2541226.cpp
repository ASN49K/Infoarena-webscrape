#include <iostream>
using namespace std;

#define fisier "euclid2"
#ifdef fisier
    #include <fstream>
    ifstream in(fisier ".in");
    ofstream out(fisier ".out");
#else
    #define in cin
    #define out cout
#endif

int n, a, b;

int cmmdc() {

    if (!b)
        return a;

    while (a %= b)
        swap(a, b);

    return b;

}

int main() {

    in >> n;

    while (n--) {

        in >> a >> b;

        out << cmmdc() << '\n';

    }

}
