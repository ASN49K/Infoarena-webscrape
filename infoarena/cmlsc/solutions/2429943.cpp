#include <fstream>
#define MAX 1026

using namespace std;

int a[MAX], b[MAX], dp[MAX][MAX], sol[MAX];

int main()
{
    int n, m, i, j, contor = 0;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> n >> m;

    for(i = 1; i <= n; i++)fin >> a[i];

    for(i = 1; i <= m; i++)fin >> b[i];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    fout << dp[n][m] << '\n';

    i = n;
    j = m;
    while(dp[i][j])
    {
        if(dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            sol[contor] = a[i];
            i--;
            j--;
            contor++;
        }
        else if(dp[i - 1][j] == dp[i][j])i--;
        else if(dp[i][j - 1] == dp[i][j])j--;
    }

    for(i = contor - 1; i >= 0; i--)fout << sol[i] << " ";

    fin.close();
    fout.close();

    return 0;
}
