#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dp[1030][1030];
int a[1030], b[1030];
int sol[1030];

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
            dp[i][j] = (a[i] == b[j] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]));
    //fout << dp[n][m];
    int lin = n, col = m, nq = 0;
    while(lin > 0 && col > 0)
    {
        if(a[lin] == b[col])
        {
            sol[nq++] = a[lin];
            lin--;
            col--;
        }
        else
        {
            if(dp[lin-1][col] >= dp[lin][col-1])
                lin--;
            else
                col--;
        }
    }
    fout << nq << "\n";
    for(int i = nq-1; i >= 0; i--)
        fout << sol[i] << " ";
    return 0;
}
