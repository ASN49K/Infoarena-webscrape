#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1024][1024], sol[1024], a[1024], b[1024], n, m, len;

int main()
{
    int i, j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                if(a[i] == b[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
        else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    for (i = n, j = m; i >= 1 && j >= 1;)
        if (a[i] == b[j])
        {
             sol[++len] = a[i];
             i--;
             j--;
        }
        else if (dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;
    fout << len << "\n";
    for(i = len; i >= 1; i--)
        fout << sol[i] << " ";
    return 0;
}
