#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int NMAX = 1030;
int n, m, dp[NMAX + 5][NMAX + 5], v[NMAX + 5], x[NMAX + 5]; //dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void build_dp()
{
    int cnt = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(v[i] == x[j])
                cnt++;

            dp[i][j] = cnt;
        }
}

void get_values(int x, int y)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(j == 1)
            {
                if(i - 1 >= 1)
                    if(dp[i - 1][m] + 1 == dp[i][1])
                        fout << v[i] << ' ';
            }
            else if(dp[i][j - 1] + 1 == dp[i][j])
                fout << v[i] << ' ';
        }

}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        fin >> v[i];
    for(int j = 1; j <= m; j++)
        fin >> x[j];

    build_dp();

    fout << dp[n][m] << '\n';

    get_values(n, m);

    fin.close();
    fout.close();
    return 0;
}
