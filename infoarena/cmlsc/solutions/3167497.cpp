#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int max_n=1025;
int dp[max_n][max_n];
int v1[max_n];
int v2[max_n];
int main()
{

    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
    for(int idx1=1;idx1<=n;idx1++)
        for(int idx2=1;idx2<=m;idx2++)
    {
        if(v1[idx1]==v2[idx2])
            dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
        else
            dp[idx1][idx2]=max(dp[idx1][idx2-1],dp[idx1-1][idx2]);
    }
    fout<<dp[n][m]<<'\n';

    int idx1=n;
    int idx2=m;
    int rasp[max_n]={0};
    int idx_rasp=dp[n][m];

    while(idx1>0 && idx2>0)
    {
        if(v1[idx1]==v2[idx2])
        {
            rasp[idx_rasp]=v1[idx1];
            idx1--;
            idx2--;
            idx_rasp--;
        }
        else if(dp[idx1-1][idx2]>dp[idx1][idx2-1])
            idx1--;
        else
            idx2--;
    }
    for(int i=1;i<=dp[n][m];i++)
        fout<<rasp[i]<<' ';
    return 0;
}
