#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, x, y;
    fin >> n;
    while (n--)
    {
        fin >> x >> y;
        fout << __gcd(x, y) << "\n";
    }

    return 0;
}
