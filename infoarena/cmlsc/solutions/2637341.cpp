#include <fstream>
#include <cstring>

const int NMAX = 1024;

int a[1+NMAX];
int b[1+NMAX];
int sol[1+NMAX];
int dp[1+NMAX][1+NMAX];

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    int n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++)
    {
       f>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
       f>>b[j];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
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

    g<<dp[n][m]<<endl;

    int lung=dp[n][m], l=n, c=m;
    while(lung > 0)
    {
       if(a[l]==b[c])
       {
           sol[lung]=a[l];
           lung--;
           l--;
           c--;
       }
       else
       {
           if(dp[l-1][c]>dp[l][c-1])
           {
               sol[lung]=a[l-1];
               lung--;
               l--;
           }
           else
           {
               sol[lung]=b[c-1];
               lung--;
               c--;
           }
       }
    }

    for(int i=1;i<=dp[n][m];i++)
    {
        g<<sol[i]<<' ';
    }

    return 0;
}

