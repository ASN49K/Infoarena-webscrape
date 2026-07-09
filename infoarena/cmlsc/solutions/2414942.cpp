#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024;

int N, M;
int v[NMAX + 5], w[NMAX + 5];

int dp[NMAX + 5][NMAX + 5];
vector <int> sol;

void Read()
{
    fin >> N >> M;

    for(int i = 1; i <= N; i++)
        fin >> v[i];

    for(int j = 1; j <= M; j++)
        fin >> w[j];
}

void Solve()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(v[i] == w[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    fout << dp[N][M] << '\n';

    int x = N, y = M;

    while(dp[x][y])
    {
        if(dp[x][y] == dp[x - 1][y])
            x--;
        else if(dp[x][y] == dp[x][y - 1])
            y--;
        else
        {
            sol.push_back(v[x]);
            x--;
            y--;
        }
    }

    for(int i = sol.size() - 1; i >= 0; i--)
        fout << sol[i] << ' ';
}

int main()
{
    Read();

    Solve();

    return 0;
}
