
#include <fstream>
#include <algorithm>
#define MAX 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int dp[MAX][MAX],na,nb,k,ok,a[MAX],b[MAX],v[MAX];
int main()
{
    int i,j;
    f>>na>>nb;
    for(i=1;i<=na;i++)
        f>>a[i];
    for(i=1;i<=nb;i++)
        f>>b[i];
    for(i=1;i<=na;i++)
        for(j=1;j<=nb;j++)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    g<<dp[na][nb]<<"\n";
    int pozx=na,pozy=nb;
    while(dp[pozx][pozy]!=0)
    {
        if(a[pozx]==b[pozy])
        {
            v[dp[pozx][pozy]]=a[pozx];
            pozx--;
            pozy--;
        }
        else
            if(dp[pozx-1][pozy]>dp[pozx][pozy-1])
                pozx--;
            else
                pozy--;
    }
    for(i=1;i<=dp[na][nb];i++)
        g<<v[i]<<" ";
}
