#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

// #define f cin
// #define g cout

int n, m;
int w[1030][1030];
struct
{
    int first, second;
} v[1030];
vector<int> rez;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> v[i].first;
    for (int i = 1; i <= m; i++)
        f >> v[i].second;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            w[i][j] = max(w[i - 1][j], w[i][j - 1]);
            if (v[i].first == v[j].second)
                w[i][j]++;
        }

    int a = n, b = m;
    while (a or b)
        if (v[a].first == v[b].second)
            rez.push_back(v[a].first), a--, b--;
        else if (w[a - 1][b] < w[a][b - 1])
            b--;
        else
            a--;

    g << w[n][m] << '\n';
    for (auto x : rez)
        g << x << " ";

    return 0;
}