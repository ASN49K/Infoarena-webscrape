#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int vn[1025],vm[1025],dp[260][260];
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>vn[i];
    for(int i=1;i<=m;i++)
        fin>>vm[i];
   for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(vn[i]==vm[j])
            dp[i][j]=1+dp[i-1][j-1];
        else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
    fout<<dp[n][m]<<endl;
    int rasp[260],cri=1,i=n,j=m;
    while(i>0&&j>0)
    {
        if(vn[i]==vm[j])
        {
            rasp[cri]=vn[i];
            cri++;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=cri;i>=1;i--)
        fout<<rasp[i]<<" ";
    return 0;
}
