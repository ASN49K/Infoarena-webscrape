#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, v[1030][1030], a[1030], b[1030], rez[1030], maxi, cnt;

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i ++) fin >> a[i];

    for (int i = 1; i <= m; i ++) fin >> b[i];

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (a[i] == b[j]) v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);

            if (v[i][j] > maxi)
            {
                maxi = v[i][j];
                rez[++ cnt] = a[i];
            }
        }
    }

    fout << maxi << '\n';

    for (int i = 1; i <= cnt; i ++) fout << rez[i] << ' ';

    return 0;
}
