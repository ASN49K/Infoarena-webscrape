#include <iostream>
#include <fstream>

using namespace std;

ifstream input("euclid2.in");
ofstream output("euclid2.out");

int cmmdc(int a, int b) {
    if (a == 0 || b == 0) return 0;
    while (a != b) {
        a -= b;
        return cmmdc(b, a);
    }
    return a;
}

int main()
{

    int T, a, b, r;

    input >> T;
    for (int i = 0; i < T; i++) {
        input >> a >> b;
        if (a > b) r = cmmdc(a, b);
        else r = cmmdc(b, a);
        output << r;
    }

    input.close();
    output.close();
}