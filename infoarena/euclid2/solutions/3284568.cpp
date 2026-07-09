#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int a, int b)
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
    int i, n, a, b;
    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << Euclid(a, b) << "\n";
    }
    return 0;
}
