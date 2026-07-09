#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int T, x, y;
    fin >> T;
    for(int i = 1; i <= T; ++i)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }

    return 0;
}
