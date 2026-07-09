#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax = 1028;
int N,M;
int a[nmax], b[nmax];
int dp[nmax][nmax];

inline void Read()
{
    fin >> N >> M;
    for(int i = 1; i <= N; i++)
        fin >> a[i];
    for(int i = 1; i <= M; i++)
        fin >> b[i];
}

inline void Rec(int x, int y)
{
    if(x == 0 || y == 0) return;
    if(a[x] == b[y])
    {
        Rec(x-1,y-1);
        fout << a[x] << " ";
    }
    else if(dp[x-1][y] > dp[x][y-1]) Rec(x-1,y);
    else Rec(x,y-1);
}

inline void Solve()
{
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
        {
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    fout << dp[N][M] << "\n";
    Rec(N,M);
}

int main()
{
    Read();
    Solve();
    return 0;
}
