#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030];
int a[1030], b[1030], n, m;

int main()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++) fin >> a[i];
    for (int i=1;i<=m;i++) fin >> b[i];

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else // de ce ?
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<int> res;
    for (int i=n, j=m; i;)
    {
        if (a[i] == b[j]) {
            res.push_back(a[i]);
            i--; j--;
        }
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;
    }

    fout << dp[n][m] << '\n';

    for (int i=res.size()-1;i>=0;i--)
        fout<<res[i]<<' ';

    return 0;
}
