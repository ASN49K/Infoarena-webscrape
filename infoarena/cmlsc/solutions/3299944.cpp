#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax=1030;
 int a[nmax];
 int b[nmax];
int dp[nmax][nmax];


void afis (int i, int j, int k)
{
    if (i==0 || j==0)
    {
        fout << k << '\n';
        return;
    }
    if (a[i]==b[j])
    {
        afis(i-1,j-1,k+1);
        fout << a[i] << " ";
    }
    else if (dp[i-1][j]>dp[i][j-1])
        afis(i-1,j,k);
    else
        afis(i,j-1,k);
}

int main()
{

    int n,m,i,j;
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
                dp[i][j]=dp[i-1][j-1]+1;

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    fout<<dp[n][m];
    afis(n,m,0);

    return 0;
}

