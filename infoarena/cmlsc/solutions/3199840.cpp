#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1000], b[1000], dp[1000][1000];
int n, m;

int mat(int x, int y)
{
    if(x>=1&&y<=m&&y>=1&&x<=n)
    {
        return 1;
    }
    return 0;
}
void functie(int x, int y, int l)
{
    if(mat(x, y)==1)
    {
        if(a[x]==b[y])
        {
            functie(x-1, y-1, l-1);
            fout<<a[x]<<" ";
        }
        else
        {
            if(dp[x-1][y]>dp[x][y-1])
            {
                functie(x-1, y, l);
            }
            else
            {
                functie(x, y-1, l);
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
    functie(n, m, dp[n][m]);
    return 0;
}
