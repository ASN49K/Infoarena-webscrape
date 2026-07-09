#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int N,M;cin>>N>>M;
    int a[N+1],b[M+1];
    for(int i=0;i<N;i++){
        cin>>a[i+1];
    }
    for(int i=0;i<M;i++){
        cin>>b[i+1];
    }
    a[0]=-1;
    b[0]=-2;
    int dp[N+1][M+1];
    for(int i=0;i<=N;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=M;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dp[i][j]=dp[i-1][j-1];
            if(a[i]==b[j]){
                dp[i][j]++;
            }
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout<<dp[N][M]<<'\n';
    stack<int> s;
    int i=N,j=M;
    while(i>=0 && j>=0){
        if(i>0 && dp[i-1][j]==dp[i][j]){
            i--;
        }
        else if(j>0 && dp[i][j-1]==dp[i][j]){
            j--;
        }
        else if(a[i]==b[j]){
            s.push(a[i]);
            i--;
            j--;
        }
        else{
            j=-5;
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}