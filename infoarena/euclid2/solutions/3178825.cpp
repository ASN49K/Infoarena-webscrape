#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int nrPer;
    fin >> nrPer;
    for (int i = 0; i < nrPer; ++i) {
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
}
/* https://infoarena.ro/problema/euclid2
idee
a, b
a % b = r;
b r.
Cand b == 0 ne oprim si returnam a

16 8
16 % 8 = 0
8, 0 ne am oprit

24 32
32 24 = 8
24 8 = 0
8 0

*/
