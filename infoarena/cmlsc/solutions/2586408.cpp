#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dp[1030][1030];
int a[1030], b[1030];
int sol[1030];
int trs[1030][1030];

int dx[] = {-1, 0, -1};
int dy[] = {-1, -1, 0};

int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                trs[i][j] = 0;
            }
            else if (dp[i][j-1] > dp[i-1][j])
            {
                dp[i][j] = dp[i][j-1];
                trs[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                trs[i][j] = 2;
            }
        }
    int lin = n, col = m, nq = 0;
    while(lin > 0 && col > 0)
    {
        int d = trs[lin][col];
        if(d == 0) sol[nq++] = a[lin];
        lin += dx[d];
        col += dy[d];
    }
    fout << nq << "\n";
    for(int i = nq-1; i >= 0; i--)
        fout << sol[i] << " ";
    return 0;
}
