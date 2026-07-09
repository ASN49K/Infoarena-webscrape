#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int N_MAX=1025;
int vn[N_MAX],vm[N_MAX],dp[256][256];
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
    int rasp[N_MAX],ri=dp[n][m],i=n,j=m;
    int cri=ri;
    while(i>0&&j>0)
    {
        if(vn[i]==vm[j])
        {
            rasp[cri]=vn[i];
            cri--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
    fout<<ri<<endl;
    for(int i=1;i<=ri;i++)
        fout<<rasp[i]<<" ";
    return 0;
}
