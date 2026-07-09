#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int dim=1064;

int na,nb,a[dim],b[dim];
int dp[dim][dim];

vector<int>ans;

signed main(){
        fin>>na>>nb;
    for(int i=1;i<=na;i++){
        fin>>a[i];
    }
    for(int i=1;i<=nb;i++){
        fin>>b[i];
    }
    for(int i=1;i<=na;i++){
        for(int j=1;j<=nb;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(a[i]==b[j]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
        fout<<dp[na][nb]<<'\n';
    while(na&&nb){
        if(a[na]==b[nb]){
            ans.push_back(a[na]);
            na--,nb--;
        }
        else{
            if(dp[na-1][nb]>dp[na][nb-1]){
                na--;
            }
            else{
                nb--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans){
        fout<<x<<' ';
    }
}
