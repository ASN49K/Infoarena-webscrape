#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int N = 1025;

int a[N], b[N], d[N][N], ans[N];

int main()
{
    ios::sync_with_stdio(false);
    fin.tie(0);

    int n, m;

    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> a[i];
    for(int i = 1; i <= m; ++i) fin >> b[i];

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    int i = n, j = m;
    while(i >= 1 && j >= 1) {
        if(a[i] == b[j]) ans[++ans[0]] = a[i], --i, --j;
        else if(d[i - 1][j] >= d[i][j - 1]) --i;
        else --j;
    }

    fout << ans[0] << "\n";
    for(int i = ans[0]; i >= 1; --i) fout << ans[i] << " ";
    return 0;
}
