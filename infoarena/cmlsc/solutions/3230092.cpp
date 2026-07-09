#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1026][1026],n,m,x[1026],y[1026],tata[1026][1026];
void rec(int i,int j){
    if(dp[i][j]!=0){
        if(x[i]==y[j]){
            rec(i-1,j-1);
            fout<<x[i]<<" ";
        }else
        if(tata[i][j]==-1)
            rec(i-1,j);
        else
            rec(i,j-1);
    }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int j=1;j<=m;j++)
        fin>>y[j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]==y[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    tata[i][j]=-1;
                }else{
                    dp[i][j]=dp[i][j-1];
                    tata[i][j]=1;
                }

            }
        }
    }
    fout<<dp[n][m]<<"\n";
    rec(n,m);
    return 0;
}
