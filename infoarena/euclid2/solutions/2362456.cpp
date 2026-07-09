#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b) {

    if (!b)
        return a;
    return cmmdc(b, a%b);
}

int main() {
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T, a, b;

    f >> T;
    for (;T; --T) {
        f >> a >> b;
        g << cmmdc(a, b) << endl;
    }

    f.close();
    g.close();

    return 0;
}
