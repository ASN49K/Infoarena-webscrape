#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax = 1024;
int n,m;
int A[Nmax+5], B[Nmax+5];
short DP[Nmax+5][Nmax+5];
int Sol[Nmax+5];

void Citire(){
    int i;
    fin>>n>>m;
    for(i = 1; i <= n; i++){
        fin>>A[i];
    }
    for(i = 1; i <= m; i++){
        fin>>B[i];
    }
}

void Solve(){
    int i,j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(A[i] == B[j]){
                DP[i][j] = DP[i-1][j-1]+1;
            }else{
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }   
    }
    fout<<DP[n][m]<<'\n';
    int x = n, y = m, k = DP[n][m];
    while(k){
        if(A[x] == B[y]){
            Sol[k] = A[x];
            x--;
            y--;
            k--;
        }else{
            if(DP[x-1][y] >= DP[x][y-1]){
                x--;
            }else{
                y--;
            }
        }
    }
    for(i = 1; i <= DP[n][m]; i++){
        fout<<Sol[i]<<' ';
    }
}

int main()
{
    Citire();
    Solve();
    return 0;
}
