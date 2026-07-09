#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int A[2000];
int B[2000];
int dp[2000][2000];
vector<int> sol;
int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fin >> A[i];
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> B[i];
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(A[i] == B[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    fout << dp[n][m] << '\n';
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int lin = n, col = m;
    int pasi_ramasi = dp[n][m];
    while(pasi_ramasi > 0)
    {
        if(dp[lin - 1][col - 1] + 1 == dp[lin][col] && dp[lin - 1][col - 1] == dp[lin - 1][col] && dp[lin - 1][col - 1] == dp[lin][col - 1])
        {
            sol.push_back(A[lin]);
            pasi_ramasi--;
            lin--;
            col--;
        }
        else
        {
            if(dp[lin - 1][col] > dp[lin][col - 1])
            {
                lin--;
            }
            else
            {
                col--;
            }
        }
    }
    reverse(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); i++)
    {
        fout << sol[i] << ' ';
    }
    fin.close();
    fout.close();
    return 0;
}
