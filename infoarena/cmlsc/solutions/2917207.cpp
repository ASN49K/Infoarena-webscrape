#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int LIM = 1050;
int n, m, v[LIM], w[LIM], dp[LIM][LIM];
stack <int> output;

int main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr), fout.tie(nullptr);

    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int i=1; i<=m; i++)
        fin>>w[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i] == w[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    int sol = dp[n][m];
    fout<<sol<<"\n";
    while(sol){
        if(v[n] == w[m]){
            output.push(v[n]);
            sol--;
            n--;
            m--;
        }else{
            if(dp[n-1][m] > dp[n][m-1]){
                n--;
            }else{
                m--;
            }
        }
    }

    while(!output.empty()){
        fout<<output.top()<<" ";
        output.pop();
    }
    return 0;
}
