#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int n;
int main()
{
    fin >> n;
    int a, b;
    for (int i = 1; i <= n; ++i) {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }
    return 0;
}
