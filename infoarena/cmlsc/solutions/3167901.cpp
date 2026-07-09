#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1002], b[1002], dp[1002][1002];
int n, m;

int inmat(int x, int y)
{
    if(x>=1&&y<=m&&y>=1&&x<=n)
    {
        return 1;
    }
    return 0;
}

void reconst_drum(int x, int y, int l)
{
    if(inmat(x, y)==1)
    {
        if(a[x]==b[y])
        {
            reconst_drum(x-1, y-1, l-1);
            fout<<a[x]<<" ";
        }
        else
        {
            if(dp[x-1][y]>dp[x][y-1])
            {
                reconst_drum(x-1, y, l);
            }
            else
            {
                reconst_drum(x, y-1, l);
            }
        }
    }
}

int main()
{
    int i, j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    fout<<dp[n][m]<<"\n";
    reconst_drum(n, m, dp[n][m]);
    return 0;
}
