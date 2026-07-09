#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("popcnt")

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int LIM = 1050;

int n, m, v[LIM + 5], w[LIM + 5];
int sol, ii, jj, dp[LIM + 5][LIM + 5];
stack<int> output;

int main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr), fout.tie(nullptr);

    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int j=1; j<=m; j++)
        fin>>w[j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i] == w[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

    sol = dp[n][m];
    ii = n;
    jj = m;

    fout<<sol<<"\n";
    while(sol != 0){
        if(v[ii] == w[jj]){
            output.push(v[ii]);
            sol--;
            ii--;
            jj--;
        }else{
            if(dp[ii-1][jj] > dp[ii][jj-1])
                ii--;
            else
                jj--;
        }
    }

    while(!output.empty()){
        fout<<output.top()<<" ";
        output.pop();
    }
    return 0;
}

