#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, a, b;
    fin >> n;
    while (n--)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
