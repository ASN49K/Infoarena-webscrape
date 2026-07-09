#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n;
int v1[1100], v2[1100];
int dp[1100][1100];
vector<int> sir;
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> v1[i];
    for (int i = 1; i <= m; i++)
        fin >> v2[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if(v1[i] == v2[j])
        {
            sir.push_back(v1[i]);
            j--;
            i--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    for (int i = sir.size() - 1; i >= 0; i--)
        fout << sir[i] << ' ';
    fout << '\n';
    return 0;
}
