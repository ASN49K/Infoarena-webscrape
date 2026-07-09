#include <iostream>
#include <fstream>
#include <deque>
#define MAXN 1050

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

deque <int> q;
int n, m, sol;
int v[MAXN], w[MAXN], dp[MAXN][MAXN];

int main(){
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int j=1; j<=m; j++)
        fin>>w[j];


    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i] == w[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);


    fout<<dp[n][m]<<"\n"; sol=dp[n][m];
    while(sol){
        if(v[n] == w[m]){
            q.push_back(v[n]);
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
