#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

deque <int> q;
int n, m, sol;
int a[1050], b[1050];
int dp[1050][1050];

int main (){
    fin>>n>>m;
    for(int i=1; i<=n; i++) fin>>a[i];
    for(int i=1; i<=m; i++) fin>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    fout<<(sol=dp[n][m])<<"\n";
    while(sol){
        if(a[n] == b[m]){
            q.push_back(a[n]);
            sol--;
            n--;
            m--;
        }else
            if(dp[n-1][m] > dp[n][m-1])
                n--;
            else
                m--;
    }
    while(!q.empty()){
        fout<<q.back()<<" ";
        q.pop_back();
    }
    return 0;
}
