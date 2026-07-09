#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int NMAX=1056;
int a[NMAX],b[NMAX],dp[NMAX][NMAX];
inline void Afis(int i,int j)
{
    if(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            Afis(i-1,j-1);
            g<<a[i]<<" ";
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                Afis(i-1,j);
            else
                Afis(i,j-1);
        }
    }
}
int main()
{
    int n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    g<<dp[n][m]<<"\n";
    Afis(n,m);
    return 0;
}
