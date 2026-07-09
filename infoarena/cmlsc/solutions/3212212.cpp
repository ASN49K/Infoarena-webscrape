#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

const int NMAX = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int n, m, a[NMAX], b[NMAX], LCS[NMAX][NMAX];
vector<int> ans;

void read()
{
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int i = 1; i <= m; i++)
        in >> b[i];
}

void lcs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                LCS[i][j] = LCS[i - 1][j - 1]+1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);

    int i = n, j = m;
    while (LCS[i][j])
        if (LCS[i][j] == LCS[i - 1][j])
            i--;
        else if (LCS[i][j] == LCS[i][j - 1])
            j--;
        else
            ans.pb(a[i]), i--, j--;
}

void solve()
{
    lcs();
    out << LCS[n][m] << '\n';

    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        out << it << ' ';
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    read();
    solve();

    return 0;
}