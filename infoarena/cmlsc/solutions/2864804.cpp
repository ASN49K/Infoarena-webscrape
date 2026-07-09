#include <fstream>

using namespace std;

#pragma GCC optimize ("Ofast")

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v1[1050], v2[1050], dp[1050][1050];
struct ura { /// ma transform in luca perju
    int cx, cy;
}pred[1050][1050];

void calc(int x, int y)
{
    if(v1[x] == v2[y])
    {
        dp[x][y] = 1 + dp[x - 1][y - 1];
        pred[x][y] = {x - 1, y - 1};
        return;
    }
    dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
    if(dp[x - 1][y] > dp[x][y - 1])
        pred[x][y] = {x - 1, y};
    else
        pred[x][y] = {x, y - 1};

}

void afis(int x, int y)
{
    if(x < 1 || y < 1)
        return;
    afis(pred[x][y].cx, pred[x][y].cy);
    if(v1[x] == v2[y])
        fout << v1[x] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v1[i];
    for(int i = 1; i <= m; i++)
        fin >> v2[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            calc(i, j);
    fout << dp[n][m] << '\n';
    afis(n, m);
    return 0;
}
