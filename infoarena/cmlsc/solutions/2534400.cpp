#include <bits/stdc++.h>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int n, m, a[1025], b[1025], mat[1025][1025], c, rez[1025], cnt;

int main(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a[i];
    }
    fin>>m;
    for(int i=1;i<=m;i++){
        fin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }else{
                mat[i][j]= max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    fout<<mat[n][m]<<endl;
    int i=n, j=m;
    while(i && j){
        if(a[i]==b[j]){
            cnt++;
            rez[cnt] = a[i];
            i--;
            j--;
        }else if(mat[i-1][j]<mat[i][j-1]){
            j--;
        }else{
            i--;
        }
    }

    for(int i=cnt;i>=1;i--){
        fout<<rez[i]<<" ";
    }
    return 0;
}
