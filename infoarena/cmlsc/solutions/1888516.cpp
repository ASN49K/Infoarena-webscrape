#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1030;

int A[NMAX], n, B[NMAX], m;
int dp[NMAX][NMAX];
int sol[NMAX], idx;

void read()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        fin >> A[i];
    for (int i = 1; i <= m; ++ i)
        fin >> B[i];
}

void solve()
{
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void print()
{
    for (int i = n, j = m; i; )
        if (A[i] == B[j])
            {
             sol[++ idx] = A[i];
             -- i;
             -- j;
            }
        else
            if (dp[i][j - 1] < dp[i - 1][j])
                -- i;
            else
                -- j;
    for (int i = idx; i; -- i)
        fout << sol[i] << " ";
    fout << "\n";
}

int main()
{
    read();
    fin.close();
    solve();
    fout << dp[n][m] << "\n";
    print();
    fout.close();
    return 0;
}
