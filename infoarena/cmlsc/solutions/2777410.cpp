#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[1030][1030],vect1[1030],vect2[1030];

void drum(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(vect1[i]==vect2[j])
    {
        drum(i-1,j-1);
        out<<vect1[i]<<' ';
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        drum(i-1,j);
    }
    else
    {
        drum(i,j-1);
    }
}

int main()
{
    int m,n;
    in>>m>>n;
    for(int i=1;i<=m;i++)
    {
        in>>vect1[i];
    }
    for(int j=1;j<=n;j++)
    {
        in>>vect2[j];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vect1[i]==vect2[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    out<<dp[m][n]<<'\n';
    drum(m,n);
    return 0;
}
