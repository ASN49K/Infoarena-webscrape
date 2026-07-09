#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1024;
int a[nmax + 5], b[nmax + 5], dp[nmax + 5][nmax + 4];


int main()
{
    int n, m;
    fin >> n >> m;
    int i, j;
    for ( i = 1; i <= n; ++i )
        fin >> a[i];

    for ( j = 1; j <= m; ++j )
        fin >> b[j];

    for ( i = 1; i <= n; ++i )
        for ( j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] );
            //fout << dp[i][j] << " ";
        }

    fout << dp[n][m] << '\n';
    vector <int> sol;
    i = n, j = m;
    while ( i > 0 && j > 0 )
    {
        if ( a[i] == b[j] )
            sol.push_back(a[i]), --i, --j;
        if ( i == 0 || j ==0 )
            break;
        if ( dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    for ( i = (int)sol.size() - 1; i >= 0; --i )
        fout << sol[i] << " ";
    return 0;
}
