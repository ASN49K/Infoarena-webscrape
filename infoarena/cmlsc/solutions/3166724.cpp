#include <bits/stdc++.h>

using namespace std;

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

#define pii pair<int, int>

const int NMAX =1e3+30;
const int INF = 0x3f3f3f3f;

int n, m, a[NMAX], b[NMAX], ansl;
int LCS[NMAX][NMAX];
vector<int> ans;

void read()
{
    in>>n>>m;
    for (int i=1; i<=n; i++)
        in>>a[i];
    for (int i=1; i<=m; i++)
        in>>b[i];
}

void lcs();

void solve()
{
    lcs();
    ansl = LCS[n][m];
    out<<ansl<<'\n';
    for (auto it : ans)
        out<<it<<' ';
}

void lcs()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                LCS[i][j] = LCS[i-1][j-1] + 1, ans.push_back(a[i]);
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);


}

int main()
{
    read();
    solve();
    return 0;
}
