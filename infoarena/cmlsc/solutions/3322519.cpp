#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N_MAX=1025;
int A[N_MAX+1],B[N_MAX+1];
int n,m;
int dp[N_MAX+1][N_MAX+1];
int seq[N_MAX+1],ind;

int maxim(int a,int b){
    return(a>b ? a:b);
}

void citire(){
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>A[i];
    for(int i=1;i<=m;i++)
        in>>B[i];
}

void sol(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i]==B[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=maxim(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}

void afis(){
    out<<dp[n][m]<<"\n";
    int i=n,j=m;
    while(i>0 && j>0){
        if(A[i]==B[j]){
            seq[++ind]=A[i];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else
            j--;
    }
    for(int i=ind;i>=1;i--)
        out<<seq[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    in.tie(NULL);
    out.tie(NULL);
    citire();
    sol();
    afis();
}