///#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N=1024;
int n,a[N+5];
int m,b[N+5];
int dp[N+5][N+5];
int st[N+5],vf=0;

int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++)fin>>a[i];
    for(int i=1;i<=m;i++)fin>>b[i];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(a[i]==b[j])
          dp[i][j]=1+dp[i-1][j-1];
        else
          dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    fout<<dp[n][m]<<"\n";
    int x=n,y=m;
    while(x>=1 && y>=1){
      if(a[x]==b[y]){
        st[++vf]=a[x];
        x--;
        y--;
        continue;
      }
      if(dp[x-1][y]==dp[x][y])
        x--;
      else
        y--;
    }
    for(int i=vf;i>=1;i--)
      fout<<st[i]<<" ";
    return 0;
}
/**

**/
