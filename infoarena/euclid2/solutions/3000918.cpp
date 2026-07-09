#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int cmmdc(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> T;
    while (T--)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
