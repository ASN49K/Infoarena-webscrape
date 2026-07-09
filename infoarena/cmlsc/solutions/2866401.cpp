#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,i,j,dp[1026][1026],n1,n2,afis[1026],depus,sir1[1026],sir2[1026],sti,stj;
int main()
{
    fin>>n1>>n2;
    for(i=1;i<=n1;i++) fin>>sir1[i];
    for(i=1;i<=n2;i++) fin>>sir2[i];
    ///dp[i][j] = cel mai lung subsir comun din din primele i elem din sir1 si primele j elem din sir2
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(sir1[i]==sir2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    fout<<dp[n1][n2]<<'\n';
    sti=n1,stj=n2;
    while(sti and stj)
    {
        if(sir1[sti]==sir2[stj])
        {
            depus++;
            afis[depus]=sir1[sti];
            sti--; stj--;
        }
        else
        {
            if(dp[sti][stj-1]>=dp[sti-1][stj]) stj--;
            else sti--;
        }
    }
    for(i=depus;i>=1;i--) fout<<afis[i]<<' ';
    return 0;
}
