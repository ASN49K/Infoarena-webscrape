#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int A[1030], B[1030], dp[1030][1030];
stack<int> sol;

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> A[i];
    for (i = 1; i <= m; i++)
        fin >> B[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    i = n; j = m;
    while (i >= 1 && j >= 1)
    {
        if (A[i] == B[j]) sol.push(A[i]);
        if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    fout << dp[n][m] << "\n";
    while (!sol.empty())
    {
        fout << sol.top() << " ";
        sol.pop();
    }
    return 0;
}
