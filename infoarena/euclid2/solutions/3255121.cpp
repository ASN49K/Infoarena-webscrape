#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc (int a, int b)
{
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int T, a, b, rezultat;
    fin >> T;

    for (int i = 1; i <= T; i ++) {
        fin >> a >> b;

        rezultat = cmmdc(a, b);
        fout << rezultat << '\n';
    }

    return 0;
}
