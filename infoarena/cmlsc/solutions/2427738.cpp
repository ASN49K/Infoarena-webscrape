#include <bits/stdc++.h>
#define MAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,A[MAX],B[MAX];
int Dp[MAX][MAX],lgmax;

void read();
void solve();
void ans();

int main(){
    read();
    solve();
    ans();
    return 0;
}
void ans(){
    int i,j,dr=m;
    stack <int> Ans;
    fout<<lgmax<<'\n';
    for(i=n;i>=1;--i)
        for(j=dr;j>=1;--j){
            if(lgmax==Dp[i][j]&&A[i]==B[j]){
                dr=j-1;
                Ans.push(A[i]);
                --i;
                --lgmax;
            }
        }
    while(!Ans.empty()){
        fout<<Ans.top()<<' ';
        Ans.pop();
    }
}
void solve(){
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(A[i]==B[j]){
                Dp[i][j]=Dp[i-1][j-1]+1;
                lgmax=max(lgmax,Dp[i][j]);
            }else
                Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
}
void read(){
    int i;
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>A[i];
    for(i=1;i<=m;++i)
        fin>>B[i];
}
