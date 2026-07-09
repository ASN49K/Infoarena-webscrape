#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline void Solve()
{
    int N, x, y;
    fin >> N;
    for(int i = 1; i <= N; i++)
    {
        fin >> x >> y;
        fout << __gcd(x, y) << "\n";
    }
}

int main()
{
    Solve();
    return 0;
}
