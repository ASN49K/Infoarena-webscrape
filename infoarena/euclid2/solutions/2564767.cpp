#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

int Gcd(int x, int y)
{
    int r;

    while(y)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    fin >> T;

    while(T--)
    {
        fin >> a >> b;

        fout << Gcd(a, b) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
