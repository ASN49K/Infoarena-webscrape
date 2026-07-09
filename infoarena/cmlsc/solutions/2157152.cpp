#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nMax = 1030;
int N, M, top;
int a[nMax], b[nMax], dp[nMax][nMax], st[nMax];

inline void Read()
{
    fin >> N >> M;
    for(int i = 1; i <= N; i++)
        fin >> a[i];
    for(int i = 1; i <= M; i++)
        fin >> b[i];
}

inline void Solve()
{
    int ans, i, j;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    ans = dp[N][M];
    fout << ans << "\n";
    i = N;
    j = M;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            st[++top] = a[i];
            i--;j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    while(top)
        fout << st[top--] << " ";
}

int main()
{
    Read();
    Solve();
    return 0;
}
