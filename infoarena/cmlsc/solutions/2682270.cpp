#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
short sir1[1027], sir2[1027], sir3[1027];
short DP[1027][1027];

int main() {
    int i,j,sl;
    fin>>n>>m;
    for(i = 1; i <= n; i++){
        fin>>sir1[i];
    }
    for(i = 1; i <= m; i++){
        fin>>sir2[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(sir1[i] == sir2[j]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }else{
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    sl = DP[n][m];
    fout<<sl<<'\n';
    i = n;
    j = m;
    while(sl){
        if(sir1[i] == sir2[j]){
            sir3[sl] = sir1[i];
            i--;
            j--;
            sl--;
        }else{
            if(DP[i-1][j] > DP[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    for(i = 1; i <= DP[n][m]; i++){
        fout<<sir3[i]<<' ';
    }
    return 0;
}
