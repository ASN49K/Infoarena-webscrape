#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a, b, t;
    fin >> t;
    while (t--)
    {
        fin >> a >> b;
        fout << __gcd(a, b) << "\n";
    }
    return 0;
}
