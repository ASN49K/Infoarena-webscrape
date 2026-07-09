#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
typedef long long ll;

int n, a, b;

int main()
{
    fin >> n;
    while (n--)
    {
        fin >> a >> b;
        fout << __gcd(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
