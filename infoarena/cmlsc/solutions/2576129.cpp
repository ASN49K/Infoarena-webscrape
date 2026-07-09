#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int s1[1050],s2[1050],sol[1050];
int DP[1050][1050];
int n,m;

int main(){
    int i,j,ok = 1,x,y,k = 0;
    fin>>n>>m;
    for(i = 1; i <= n; i++){
        fin>>s1[i];
    }
    for(i = 1; i <= m; i++){
        fin>>s2[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(s1[i] == s2[j]){
                DP[i][j] = DP[i-1][j-1]+1;
            }else{
                DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
            }
        }
    }
    x=n;
    y=m;
    fout<<DP[x][y]<<'\n';
    while(ok){
        if(s1[x] == s2[y]){
            sol[k++] = s1[x];
            x--;
            y--;
            if(DP[x][y] == 0){
                ok = 0;
            }
        }else{
            if(DP[x-1][y] >= DP[x][y-1]){
                x--;
            }else{
                y--;
            }
        }
    }
    for(i = k-1; i >= 0; i--){
        fout<<sol[i]<<' ';
    }
    return 0;
}
