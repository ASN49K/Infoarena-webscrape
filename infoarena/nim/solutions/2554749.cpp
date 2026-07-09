#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t;
    f >> t;
    while (t --)
    {
        int n;
        f >> n;
        int xorSum = 0;
        for (int i = 1; i <= n; ++ i)
        {
            int x;
            f >> x;
            xorSum ^= x;
        }
        if (xorSum == 0)
            g << "NU" << '\n';
        else
            g << "DA" << '\n';
    }
}
