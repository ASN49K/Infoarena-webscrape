#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[101], b[101], mat[101][101], c, rez[101], cnt=1;

int main(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    fin>>m;
    for(int i=1;i<=m;i++){
        fin>>b[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }else{
                mat[i][j]= max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    int i=n, j=m;
    while(i && j){
        if(a[i]==b[j]){
            rez[cnt++] = a[i];
            i--;
            j--;
        }else if(mat[i-1][j]<mat[i][j-1]){
            j--;
        }else{
            i--;
        }
    }
    for(int i=cnt-1;i>=1;i--){
        fout<<rez[i]<<" ";
    }
    return 0;
}
