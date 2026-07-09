#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int q, a, b;

int cmmdc(int a, int b)
{
    int r;
    r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    fin >> q;
    while(q--)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
