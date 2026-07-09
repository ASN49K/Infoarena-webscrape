#include <fstream>

#define nMax 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int A[nMax], B[nMax], dp[nMax][nMax];
void read()
{
    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>A[i];

    for(int i=1;i<=m;i++)
        fin>>B[i];
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<'\n';
}
void write(int lin, int col)
{
    if(lin<1 || col<1)
        return;

    if(A[lin]==B[col])
    {
        write(lin-1, col-1);
        fout<<A[lin]<<" ";
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
    read();
    solve();
    write(n, m);
    return 0;
}
