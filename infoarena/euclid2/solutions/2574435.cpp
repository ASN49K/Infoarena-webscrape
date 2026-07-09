#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int N, a, b;

int main()
{
    fin >> N;
    while (N--)
    {
        fin >> a >> b;
        fout << __gcd(a, b) << "\n";
    }
    return 0;
}
