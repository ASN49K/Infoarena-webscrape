#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int s, n, q;

int main()
{
    f >> q;

    for(; q--;)
    {
        f >> n;
        s = 0;
        for(int i = 1; i <= n; i++)
        {
            int x;
            f >> x;
            s ^= x;
        }

        if(s == 0)
            g << "NU\n";
        else
            g << "DA\n";
    }

    return 0;
}
