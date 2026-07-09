#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int VMAX = 1030;
int n, m, a[VMAX], b[VMAX], mt[VMAX][VMAX];
vector<int> subsir;
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL), fout.tie(NULL);
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
    fin >> a[i];
    for (int i = 1; i <= m; ++i)
    fin >> b[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                mt[i][j] = 1 + mt[i - 1][j - 1];
            else
                mt[i][j] = max(mt[i - 1][j], mt[i][j - 1]);
    for (int i = n, j = m; i and j;)
    {
        if (a[i] == b[j])
        {
            subsir.push_back(a[i]);
            --i, --j;
        }
        else if (mt[i][j - 1] < mt[i - 1][j])
            --i;
        else --j;
    }
    fout << mt[n][m] << "\n";
    for (int i = mt[n][m] - 1; i >= 0; --i)
    fout << subsir[i] << " ";
    fin.close(), fout.close();
    return 0;
}
