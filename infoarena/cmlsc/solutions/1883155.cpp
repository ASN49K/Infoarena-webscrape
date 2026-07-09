#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N = 1024;

int n, m, a[N], b[N], dp[N+1][N+1], p[N][N];

void afis(int i, int j)
{
    if(p[i][j]==0)
        return;
    else if(p[i][j]==1)
        afis(i-1, j-1), fout<<a[i]<<" ";
    else if (p[i][j]==2)
        afis(i-1, j);
    else
        afis(i, j-1);
}

int main()
{
    fin>>n>>m;
    for(int i=0;i<n;i++)
        fin>>a[i];
    for(int i=0;i<n;i++)
        fin>>b[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
                dp[i+1][j+1]=dp[i][j]+1, p[i][j]=1;
            else if(dp[i][j+1]>=dp[i+1][j])
                dp[i+1][j+1]=dp[i][j+1], p[i][j]=2;
            else
                dp[i+1][j+1]=dp[i+1][j], p[i][j]=3;
        }

    fout<<dp[n][m]<<'\n';
    afis(n-1, m-1);

    return 0;
}
