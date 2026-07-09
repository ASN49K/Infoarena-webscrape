#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int a, b, n, i;
    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    fout.close();
    return 0;
}
