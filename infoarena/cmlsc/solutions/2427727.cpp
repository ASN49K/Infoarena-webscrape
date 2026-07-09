#include <bits/stdc++.h>

#define Nmax 1024

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int N, M;

int A[1 + Nmax + 5];
int B[1 + Nmax + 5];

int DP[1 + Nmax + 5][1 + Nmax + 5];

int Answers[1 + Nmax + 5];
int ans = 0;

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; ++i)
        fin >> A[i];
    for (int i = 1; i <= M; ++i)
        fin >> B[i];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
                DP[i][j] = 1 + DP[i - 1][j - 1];
            else
                DP[i][j] = max (DP[i - 1][j], DP[i][j - 1]);
    for (int i = N, j = M; i && j; )
        if (DP[i][j] == DP[i - 1][j])
            --i;
        else if (DP[i][j] == DP[i][j - 1])
                --j;
            else Answers[++ans] = A[i], --i, --j;
    fout << ans << "\n";
    for (int i = ans; 1 <= i; --i)
        fout << Answers[i] << " ";
    return 0;
}
