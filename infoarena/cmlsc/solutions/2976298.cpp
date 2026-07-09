
#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

// #define f cin
// #define g cout

int n, m;
vector<int> rez;

int main()
{
    ios_base::sync_with_stdio(false);
    f.tie(nullptr);

    f >> n >> m;
    int v[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            v[i][j] = 0;

    for (int i = 1; i <= n; i++)
        f >> v[0][i];
    for (int i = 1; i <= m; i++)
        f >> v[i][0];

    for (int i = 1; i <= n; i++)
        if (v[0][i] == v[1][0])
            v[1][i] = 1, rez.push_back(v[1][0]);

    for (int i = 1; i <= m; i++)
        if (v[i][0] == v[0][1])
            v[i][1] = 1, rez.push_back(v[i][0]);

    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
        {
            v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            if (v[0][j] == v[i][0])
                v[i][j]++,
                    rez.push_back(v[i][0]);
        }

    g << rez.size() << '\n';
    for (auto x : rez)
        g << x << " ";

    return 0;
}