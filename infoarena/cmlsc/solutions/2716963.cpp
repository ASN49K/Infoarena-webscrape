#include<bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short mat[1030][1030];
short A[1030], B[1030];
short sol[1030];
int n,m;

int main(){
    int i,j,x,y,length;
    fin>>n>>m;
    for(i = 1; i <= n; i++){
        fin>>A[i];
    }
    for(i = 1; i <= m; i++){
        fin>>B[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(A[i] == B[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }else{
                mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
            }
        }
    }
    x = n;
    y = m;
    length = mat[n][m];
    fout<<length<<'\n';
    while(length != 0){
        if(A[x] == B[y]){
            sol[length] = A[x];
            x--;
            y--;
            length--;
        }else{
            if(mat[x][y-1] > mat[x-1][y]){
                y--;
            }else{
                x--;
            }
        }
    }
    for(i = 1; i <= mat[n][m]; i++){
        fout<<sol[i]<<' ';
    }
	return 0;
}
