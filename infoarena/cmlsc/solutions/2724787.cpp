#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N_MAX = 1025;

int N, M, v1[N_MAX], v2[N_MAX];
int dp[N_MAX][N_MAX];

void Solve()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void Construct(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (v1[i] == v2[j])
    {
        Construct(i - 1, j - 1);
        fout << v1[i] << " ";
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            Construct(i - 1, j);
        else
            Construct(i, j - 1);
    }
}

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
        fin >> v1[i];
    for (int i = 1; i <= M; i++)
        fin >> v2[i];
    Solve();
    fout << dp[N][M] << "\n";
    Construct(N, M);
    return 0;
}
