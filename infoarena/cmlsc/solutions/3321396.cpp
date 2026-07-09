#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int MAX_NR=1025;
int A[MAX_NR],n;
int B[MAX_NR],m;
int dp[MAX_NR][MAX_NR];
int seq[MAX_NR],ind;

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

void calc_dp(){
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

void calc_seq(){
    int i=n,j=m;
    while(i>0 && j>0){
        if(A[i]==B[j]){
            seq[++ind]=A[i];
            i--,j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
}

void afis(){
    int len=dp[n][m];
    cout<<len<<"\n";
    for(int i=ind;i>=1;i--)
        cout<<seq[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    in.tie(NULL);
    out.tie(NULL);
    citire();
    calc_dp();
    calc_seq();
    afis();
}