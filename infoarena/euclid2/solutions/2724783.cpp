#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int N, x, y;

int main()
{
    fin >> N;
    while (N--)
    {
        fin >> x >> y;
        fout << __gcd(x, y) << "\n";
    }
    return 0;
}
