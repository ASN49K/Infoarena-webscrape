#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nMax = 1030;
int N, M, top;
int st[nMax], a[nMax], b[nMax], dp[nMax][nMax];

inline void Solve()
{
    int i, j;
    fin >> N >> M;
    for(i = 1; i <= N; i++)
        fin >> a[i];
    for(i = 1; i <= M; i++)
        fin >> b[i];
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[N][M] << "\n";
    i = N; j = M;
    while(i && j)
    {
        if(a[i] == b[j])
            st[++top] = a[i], i--, j--;
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    for(i = top; i >= 1; i--)
        fout << st[i] << " ";
}

int main()
{
    Solve();
    return 0;
}
