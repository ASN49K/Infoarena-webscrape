#include <fstream>


using namespace std;

int n,m,dp[2025][2025];
int s[2025],t[2025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>s[i];
    for(int i=1;i<=m;i++)
        fin>>t[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i]==t[j])
                dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
    fout<<dp[n][m]<<'\n';
    int i = n,j = m;
    int rez[1025],cnt = 0;
    while(i!=0 ){
        if(s[i]==t[j]){
            rez[++cnt]=s[i];
            i--,j--;
        }
        else{
            if(dp[i-1][j]>=dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int i=cnt;i>=1;i--)
        fout<<rez[i]<<" ";
    return 0;
}
