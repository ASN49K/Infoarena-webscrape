#include <bits/stdc++.h>
#define N_MAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N1, N2, v1[N_MAX], v2[N_MAX];
int dp[N_MAX][N_MAX];
pair < int, int > Ans[N_MAX][N_MAX];

void GenAns(int x, int y)
{
    if (Ans[x][y] != make_pair(0, 0))
        GenAns(Ans[x][y].first, Ans[x][y].second);
    if (v1[x] == v2[y])
        fout << v1[x] << " ";
}

int main()
{
    fin >> N1 >> N2;
    for (int i = 1; i <= N1; i++)
        fin >> v1[i];
    for (int i = 1; i <= N2; i++)
        fin >> v2[i];

    for (int i = 1; i <= N1; i++)
        for (int j = 1; j <= N2; j++)
        {
            if (v1[i] == v2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                Ans[i][j] = make_pair(i - 1, j - 1);
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                Ans[i][j] = make_pair(i - 1, j);
            }
            else if (dp[i - 1][j] < dp[i][j - 1])
            {
                dp[i][j] = dp[i][j - 1];
                Ans[i][j] = make_pair(i, j - 1);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (i - 1 > 0)
                    Ans[i][j] = make_pair(i - 1, j);
                else
                    Ans[i][j] = make_pair(i, j - 1);
            }
        }

    fout << dp[N1][N2] << "\n";
    GenAns(N1, N2);
    return 0;
}
