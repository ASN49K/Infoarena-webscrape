#include <fstream>
#include <stack>

using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
const int nmax=1024;
int n, m;
int X[nmax+5], Y[nmax+5], sol[nmax+5];
int dp[nmax+5][nmax+5];

int main()
{
    fi>>n>>m;
    for(int i=1; i<=n; i++)
        fi>>X[i];
    for(int i=1; i<=m; i++)
        fi>>Y[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(X[i]==Y[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
    fo<<dp[n][m]<<"\n";
    for(int i=n, j=m, k=dp[n][m]; i>0 && j>0; )
    {
        if(X[i]==Y[j])
        {
            sol[k--]=X[i--];
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int i=1; i<=dp[n][m]; i++)
        fo<<sol[i]<<" ";
    fi.close();
    fo.close();
    return 0;
}
