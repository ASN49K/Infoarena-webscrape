#include <iostream>
#include <fstream>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dp[1050][1050];
int n, m, v[1050], w[1050];

void go(int x, int y){
    if(x > 0 && y > 0){
        if(v[x] == w[y]){
            go(x-1, y-1);
            fout<<v[x]<<" ";
        }else{
            if(dp[x-1][y] > dp[x][y-1])
                go(x-1, y);
            else
                go(x, y-1);
        }
    }
}

int main (){
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

    fout<<dp[n][m]<<"\n";
    go(n, m);
    return 0;
}
