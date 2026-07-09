#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025];
int main()
{
    int n,m,vn[1025],vm[1025];
    fin>>n>>m;
    for (int i = 1; i <= n; i++)
        fin >> vn[i];
    for(int i = 1; i <= m; i++)
        fin>>vm[i];
    for(int i = 1; i <= n; i++)
        for(int j=1; j <= m; j++)
        {
            if(vn[i]==vm[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    fout<<dp[n][m]<<endl;
    int i=n,j=m,rasp[1025],ri=dp[n][m];
    while(i>0||j>0)
    {
        if(vn[i]==vm[j])
        {
            rasp[ri]=vn[i];
            ri--;
            i--;
            j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else j--;
        }
    }
    for(int i=1; i<=dp[n][m]; i++)
        fout<<rasp[i]<<" ";
    return 0;
}
