#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int x, y;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> x >> y;
        fout << gcd(x, y) << '\n';
    }
    return 0;
}
