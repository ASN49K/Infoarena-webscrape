#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int MAX_N=1025;
int dp[MAX_N][MAX_N];

//void subprogram
int main(){
    int n,m;
    int v1[MAX_N],v2[MAX_N];
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int j=1;j<=m;j++)
        fin>>v2[j];

    for(int idx1=1; idx1<=n; idx1++){
        for(int idx2; idx2<=m; idx2++)
            if(v1[idx1]==v2[idx2]){
                dp[idx1][idx2]=1+dp[idx1][idx2-1];
            }
            else{
                dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
    }
    fout<<dp[n][m]<<'\n';
    int idx1=n, idx2=m;
    int ans[MAX_N];
    int idx_ans=dp[n][m];

    while(idx1>0 && idx2>0){
        if(v1[idx1]==v2[idx2]){
            ans[idx_ans]=v1[idx1];
            idx_ans--;
            idx1--;
            idx2--;
        }
        else if(dp[idx1-1][idx2]>dp[idx1][idx2-1]){
            idx1--;
        }
        else{
            idx2--;
        }
    }
    for(int idx=1; idx<=dp[n][m]; idx++)
        fout<<ans[idx]<<' ';


    return 0;
}
