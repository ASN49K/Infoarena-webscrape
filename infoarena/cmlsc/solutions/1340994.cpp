#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m;
int a[1025],b[1025];
int dp[1025][1025];
//dp[i][j]= cmlsc formate cu primele i elemente ale subsirului A
//          si primele j elemente ale sirului B
void Citire()
{
    int i;
    f>>m>>n;
    for(i=1;i<=m;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        f>>b[i];
    }
}

void Cmlsc()
{
    int i,j;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    {
        if(a[i]!=b[j])
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        else if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
    }
    g<<dp[m][n]<<"\n";

    for(i=m;i>0;)
        for(j=n;j>0;)
        {
            if(a[i]==b[j] )
            {
                g<<a[i]<<" ";
                i--;j--;
            }
            else
            {
                if(dp[i-1][j]<dp[i][j-1])
                {
                    j--;
                }
                else i--;
            }
        }
}
int main()
{
    Citire();
    Cmlsc();
    return 0;
}
