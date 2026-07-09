#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sol[1030];
int A[1030][1030];
int v[1030];
int u[1030];
void construct_sol(int x, int y, int length){
    if(length != 0){
        if(A[x][y] > max(A[x-1][y], A[x][y-1])){
            sol[length] = v[x];
            length--;
            x--;
            y--;
            construct_sol(x, y, length);
        } else if(A[x][y] == A[x-1][y]){
            x--;
            construct_sol(x, y, length);
        } else {
            y--;
            construct_sol(x, y, length);
        }
    }
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    for(int i = 1; i<=n; i++){
        cin>>u[i];
    }
    for(int i=0; i<=n; i++){
        A[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        A[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(v[i] == u[j]){
                A[i][j] = A[i-1][j-1] + 1;
            } else {
                A[i][j] = max(A[i-1][j], A[i][j-1]);
            }
        }
    }
    cout<<A[n][m]<<'\n';
    construct_sol(n, m, A[n][m]);
    for(int i = 1; i<=A[n][m]; i++){
        cout<<sol[i]<<" ";
    }
    return 0;
}
