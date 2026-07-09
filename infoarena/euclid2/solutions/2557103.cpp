#include <bits/stdc++.h>

using namespace std;

#define ll int
#define INF 1234567890
#define N (int)(2e5 + 5)
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    ios::sync_with_stdio(false);
    fin.tie(0);
    int t;
    fin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int a, b;
        fin >> a >> b;
        fout << __gcd(a, b) << "\n";
    }
    return 0;
}
