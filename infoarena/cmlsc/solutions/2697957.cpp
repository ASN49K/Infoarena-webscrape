#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX=1024;

int dp[NMAX][NMAX];

void LCS(int v1[],int v2[],int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(v1[i-1]==v2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int nr=dp[n][m],lcs[nr+1],i=n,j=m;
    while(i>0&&j>0){
        if(v1[i-1]==v2[j-1]){
            lcs[nr-1]=v1[i-1];
            i--;j--;nr--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    out<<dp[n][m]<<'\n';
    for(int i=0;i<dp[n][m];i++){
        out<<lcs[i]<<" ";
    }
}

int main()
{
    int v1[NMAX],v2[NMAX],n,m;
    in>>n>>m;
    for(int i=0;i<n;i++){
        in>>v1[i];
    }
    for(int i=0;i<m;i++){
        in>>v2[i];
    }
    LCS(v1,v2,n,m);
    return 0;
}
