#include <bits/stdc++.h>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

const int nmax = 2e3 + 3;

int n, m, d[nmax][nmax], v1[nmax], v2[nmax];

int main()
{
    f >> n >> m;

    for (int i = 1; i <= n; ++i)
        f >> v1[i];

    for (int i = 1; i <= m; ++i)
        f >> v2[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (v1[i] == v2[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    g << d[n][m] << '\n';

    int t1 = n;
    int t2 = m;

    vector <int> sol;

    while (t1 && t2)
    {
        if (v1[t1] == v2[t2])
        {
            sol.push_back(v1[t1]);
            --t1;
            --t2;
        }

        else
        {
            if (d[t1][t2 - 1] <= d[t1 - 1][t2])
                --t1;
            else
                --t2;
        }
    }

    reverse(sol.begin(), sol.end());
    for (auto it: sol)
        g << it << ' ';

    return 0;
}
