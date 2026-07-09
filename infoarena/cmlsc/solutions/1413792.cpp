#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M;
int sol[1027], nrsol;
int A[1027], B[1027], dp[1027][1027];

int main()
{
    fin >> N >> M;
    for (int i = 1; i <= N; ++i)
        fin >> A[i];
    for (int i = 1; i <= M; ++i)
        fin >> B[i];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    int x = N, y = M;
    while (x && y)
    {
        if (dp[x - 1][y] == dp[x][y])
            --x;
        else if (dp[x][y - 1] == dp[x][y])
            --y;
        else
        {
            sol[++nrsol] = A[x];
            --x;
            --y;
        }
    }

    fout << dp[N][M] << '\n';
    for (int i = nrsol; i >= 1; --i)
        fout << sol[i] << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
