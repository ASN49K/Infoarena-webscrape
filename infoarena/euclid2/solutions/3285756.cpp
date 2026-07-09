#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, x, y;

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
    int i;
    fin >> t;
    for (i = 1 ; i <= t ; i++)
    {
        fin >> x >> y;
        fout << Euclid(x, y) << "\n";
    }
    return 0;
}
