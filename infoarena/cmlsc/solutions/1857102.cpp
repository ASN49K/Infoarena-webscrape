#include <fstream>

#define nMax 1025
#define mMax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[nMax], b[nMax], dp[nMax][mMax];

void write(int lin, int col)
{
    if(lin<1 || col<1)
        return;
    if(a[lin]==b[col])
    {
        write(lin-1, col-1);
        fout<<a[lin]<<" ";
    }
    else
    {
        if(dp[lin][col]==dp[lin-1][col])
            write(lin-1, col);
        else
            write(lin, col-1);
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<'\n';
    write(n, m);
}
