#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N_MAX = 1030;

int n, m;
int A[N_MAX], B[N_MAX];

int dp[N_MAX][N_MAX];

int leven_dist()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j -  1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}

void construct(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (A[i] == B[j])
    {
        construct(i - 1, j - 1);
        fout << A[i] << " ";
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
        construct(i - 1, j);
    else
        construct(i, j - 1);
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> A[i];
    for (int i = 1; i <= m; i++)
        fin >> B[i];
    fout << leven_dist() << "\n";
    construct(n, m);
    return 0;
}
