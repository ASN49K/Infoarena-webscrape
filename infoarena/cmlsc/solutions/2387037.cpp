#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int i,j,n,m,v1[1026],v2[1026];
struct dinamica
{
    int val;
    vector <int> subsir;
} dp[1026][1026];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
    for(i=0;i<=n;i++)
        dp[i][0].val=0;
    for(i=1;i<=m;i++)
        dp[0][i].val=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                dp[i][j].val=dp[i-1][j-1].val+1;
                for(auto par : dp[i-1][j-1].subsir)
                    dp[i][j].subsir.push_back(par);
                dp[i][j].subsir.push_back(v1[i]);
            }
            else
            {
                if(dp[i][j-1].val > dp[i-1][j].val)
                {
                    dp[i][j].val=dp[i][j-1].val;
                    for(auto par : dp[i][j-1].subsir)
                        dp[i][j].subsir.push_back(par);
                }
                else
                {
                    dp[i][j].val=dp[i-1][j].val;
                    for(auto par : dp[i-1][j].subsir)
                        dp[i][j].subsir.push_back(par);
                }
            }
        }
    fout<<dp[n][m].val<<'\n';
    for(auto par : dp[n][m].subsir)
        fout<<par<<' ';
    return 0;
}
