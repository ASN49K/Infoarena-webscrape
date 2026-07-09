#include <bits/stdc++.h>

using namespace std;

ifstream fin ("divmul.in");
ofstream fout ("divmul.out");

int cmmdc (int a, int b)
{
    while (b != 0)
    {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main()
{
    int n, x, y, c, cnt;

    fin >> n ;

    for (int j=1; j<=n; j++)
    {
        cnt = 0;

        fin >> x >> y;

        if (y % x == 0)
        {
            y = y/x;

            for (int i=1; i*i<=y; i++)
            {
                if (y % i == 0)
                    if (cmmdc(i, y/i) == 1) cnt += 2;
            }
        }

        fout << cnt << '\n';
    }

    return 0;
}
