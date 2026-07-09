#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int cmmdc(int a, int b)
{
    if(!b)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    int a, b;

    fin >> n;
    while(n--)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
