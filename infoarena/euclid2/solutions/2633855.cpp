#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

typedef unsigned int uint;

uint cmmdc(uint a, uint b) {
    uint tmp;
    while (b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int main()
{
    uint T;
    fin >> T;
    while (T--) {
        uint a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';

    }

    return 0;
}
