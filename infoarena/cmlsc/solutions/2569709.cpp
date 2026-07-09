#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
const int nmax=1030,mmax=1030;
int n,m;
int a[nmax],b[mmax],dp[nmax][mmax],rez[nmax][mmax];
void afisare (int i,int j)
{
    if (i>=1 && i<=n && j>=1 && j<=m)
    {
        if (rez[i][j]==0)
        {
            afisare(i-1,j-1);
            fout << a[i] << " ";
        }
        else if (rez[i][j]==1) afisare(i-1,j);
        else if (rez[i][j]==2) afisare(i,j-1);
    }
}
int main()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        fin >> a[i];
    }
    for (int i=1;i<=m;i++)
    {
        fin >> b[i];
    }
    for (int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for (int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
                rez[i][j]=0;
            }
            else
            {
                if (dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    rez[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    rez[i][j]=2;
                }
            }
        }
    }
    fout << dp[n][m] << '\n';
    afisare(n,m);
}
