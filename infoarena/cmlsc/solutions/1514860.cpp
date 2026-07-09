#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1024;

int dp[MAX_N + 1][MAX_N + 1];
int A[MAX_N + 1], B[MAX_N + 1];

int N, M;

void printSolution(int i, int j, ostream &out)
{
    if (1 <= i && 1 <= j)
    {
        if (A[i] == B[j])
        {
            printSolution(i - 1, j - 1, out);
            out << A[i] << ' ';
        }
        else
        {
            if (dp[i][j - 1] >= dp[i - 1][j])
                printSolution(i, j - 1, out);
            else
                printSolution(i - 1, j, out);
        }
    }
}

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in >> N >> M;

    for (int i = 1; i <= N; ++i)
        in >> A[i];

    for (int i = 1; i <= M; ++i)
        in >> B[i];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    out << dp[N][M] << "\n";
    printSolution(N, M, out);

    return 0;
}
