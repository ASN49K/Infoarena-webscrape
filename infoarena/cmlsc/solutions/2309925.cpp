#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,m,n,a[1025],b[1025],dp[1025][1025],k,sir[1025];
void rec(int x, int y)
{
    if(dp[x][y]!=0)
    {
        if(dp[x][y]==dp[x-1][y-1]+1)
        {
            k++;
            sir[k]=a[x];
            rec(x-1,y-1);
        }
        else
        if(dp[x][y]== dp[x-1][y])
            rec(x-1,y);
        else
            if(dp[x][y]==dp[x][y-1])
            rec(x,y-1);

    }

}
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    fout<<dp[m][n]<<'\n';
    rec(m,n);
    for(i=k;i>=1;i--)
        fout<<sir[i]<<' ';
    return 0;
}
