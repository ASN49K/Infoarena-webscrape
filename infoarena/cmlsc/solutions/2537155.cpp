#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int DP[1030][1030];
int n,m;
int A[1030];
int B[1030];

void rec(int k,int x,int y){
    if(k == 0){
        return;
    }
    if(A[y] == B[x]){
        rec(k-1,x-1,y-1);
        fout<<A[y]<<' ';
    }else{
        if(DP[y][x] == DP[y-1][x]){
            rec(k,x,y-1);
        }else{
            rec(k,x-1,y);
        }
    }
}

int main()
{
    int i,j,x,y,k = 0;
    fin>>n>>m;
    for(i = 1; i <= n; i++){
        fin>>A[i];
    }
    for(i = 1; i <= m; i++){
        fin>>B[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m ;j++){
            if(A[i] == B[j]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }else{
                DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
            }
        }
    }
    fout<<DP[n][m]<<'\n';
    rec(DP[n][m],m,n);
    return 0;
}
