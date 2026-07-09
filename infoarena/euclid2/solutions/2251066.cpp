#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

long long Cmmdc (long long a, long long b)
{
    if (!b) return a;
    else return Cmmdc(b, a%b);
}

int main()
{
    long long q, a, b;
    fin >> q;
    while (q--)
    {
        fin >> a >> b;
        fout << Cmmdc(a, b) << "\n";
    }
    return 0;
}
