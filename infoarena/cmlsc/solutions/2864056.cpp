#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int DIM = 1050;

int dp[DIM][DIM], a[DIM], b[DIM];
int n, m, sol;

stack <int> q;

int main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr);
    fout.tie(nullptr);

    fin>>n>>m;
    for(int i=1; i<=n; i++) fin>>a[i];
    for(int i=1; i<=m; i++) fin>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    sol = dp[n][m];
    fout<<sol<<"\n";
    while(sol != 0){
        if(dp[n][m] == dp[n-1][m-1] + 1){
            q.push(a[n]);
            sol--;
            n--;
            m--;
        }else{
            if(dp[n-1][m] < dp[n][m-1])
                m--;
            else
                n--;
        }
    }
    while(!q.empty()){
        fout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}
