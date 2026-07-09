#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dp[1025][1025], n, m, v1[1025], v2[1025], rez[1024*1024+1], k;

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v1[i];
    for(int i=1; i<=m; i++)
        fin>>v2[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        if(v1[i]==v2[j])
        {
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else
        {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<'\n';
    int i=n, j=m;
    while(i>=1 && j>=1)
    {
        if(v1[i]==v2[j])
        {
            k++;
            rez[k]=v1[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(int i=k; i>=1; i--)
        fout<<rez[i]<<' ';
    return 0;
}
