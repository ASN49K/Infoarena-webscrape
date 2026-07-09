#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc (int x, int y)
{
    while (y)
    {
        int r = x % y;
        x = y, y = r;
    }

    return x;
}

int main()
{
    int n, a, b;

    fin >> n;

    for (int i = 1; i <= n ; i++)
    {
        fin >> a >> b;

        fout << cmmdc (a, b) << '\n';
    }

    return 0;
}
