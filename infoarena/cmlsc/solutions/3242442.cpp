#include <fstream>


using namespace std;

int v[2005],w[2005],n,m,dp[2001][2001];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
    fin >>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v[i];
    for(int j=1;j<=m;j++)
        fin>>w[j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(v[i]==w[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<'\n';
    int i = n, j = m, rez[1005],k=0;
    while(i>1){
        if(v[i]==w[j])
            rez[++k]=v[i],i--,j--;
        else
            if(dp[i-1][j]>=dp[i][j-1])
                i--;
            else
                j--;
    }
    for(int i=k;i>=1;i--)
        fout<<rez[i]<<" ";
    return 0;
}
