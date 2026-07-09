#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b , a % b);
}

int T, a, b;

int main()
{
    fin >> T;

    for (; T; --T)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }

    return 0;
}
