#include <bits/stdc++.h>
#define INFILE "euclid2.in"
#define OUTFILE "euclid2.out"

using namespace std;

ifstream f(INFILE);
ofstream g(OUTFILE);

int n;
int nr1, nr2;

int cmmdc(int nr1, int nr2) {
    if (nr2 == 0)
        return nr1;

    return cmmdc(nr2, nr1 % nr2);
}

int main() {

    f >> n;

    for (int i = 1; i <= n; i++) {
        f >> nr1 >> nr2;
        g << cmmdc(nr1, nr2) << "\n";
    }

    return 0;
}
