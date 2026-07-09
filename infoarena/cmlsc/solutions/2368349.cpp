#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1030;

int N, M;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];

vector <int> sol;

int main()
{
    fin >> N >> M;

    for(int i = 1; i <= N; i++)
        fin >> a[i];

    for(int i = 1; i <= M; i++)
        fin >> b[i];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[N][M] << '\n';

    int x = N, y = M, k = dp[N][M];

    while(k != 0)
    {
        if(dp[x - 1][y] == dp[x][y])
            x--;
        else if(dp[x][y - 1] == dp[x][y])
            y--;
        else
        {
            sol.push_back(a[x]);
            x--, y--, k--;
        }
    }

    for(int i = sol.size() - 1; i >= 0; i--)
        fout << sol[i] << ' ';

    return 0;
}
