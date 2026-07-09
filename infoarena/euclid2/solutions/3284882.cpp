#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int cmmdc(int a, int b) {
    while(b) {
        int rest = a % b;
        a = b, b = rest;
    }
    return a;
}

int main()
{
    int tt; fin >> tt;
    while(tt--) {
        int a, b; fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
