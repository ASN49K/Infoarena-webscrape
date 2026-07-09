#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int tt, a, b;

inline int cmmdc(int a, int b) {
    while(b != 0) {
        int rest = a % b;
        a = b, b = rest;
    }
    return a;
}

int main()
{
    fin >> tt;
    while(tt--) {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
