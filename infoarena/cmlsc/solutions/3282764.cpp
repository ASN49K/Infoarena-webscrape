#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int N, M;
int A[1030], B[1030], dp[1030][1030];
stack<int> sol;

int main()
{
    int i, j;
    fin >> N >> M;
    for (i = 1; i <= N; i++)
        fin >> A[i];
    for (i = 1; i <= M; i++)
        fin >> B[i];
    dp[0][0] = 0;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++)
            if (A[i] == B[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[N][M] << "\n";
    i = N; j = M;
    while (i >= 1 && j >= 1)
    {
        if (A[i] == B[j])
        {
            sol.push(A[i]);
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])i--;
        else j--;
    }
    while (!sol.empty())
    {
        fout << sol.top() << " ";
        sol.pop();
    }
    return 0;
}
