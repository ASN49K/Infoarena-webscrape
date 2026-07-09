#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int max_n=1025;
int v1[max_n],v2[max_n];
int dp[max_n][max_n]={};
int main()
{
    
    int n,m;
    
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int j=1;j<=m;j++)
        fin>>v2[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    fout<<dp[n][m]<<'\n';
    int ind1=n;
    int ind2=m;
    
    int indras=dp[n][m];
    int rasp[max_n]={};
    while(ind1>0 && ind2>0)
    {
        if(v1[ind1]==v2[ind2])
        {
            rasp[indras]=v1[ind1];
            ind1--;
            ind2--;
            indras--;
        }
        else if(dp[ind1-1][ind2]>dp[ind1][ind2-1])
            ind1--;
        else
            ind2--;
    }
    for(int i=1;i<=dp[n][m];i++)
    {
        fout<<rasp[i]<<' ';
    }
    return 0;
}
    
