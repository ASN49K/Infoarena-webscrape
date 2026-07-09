#include <iostream>
#include <fstream>
#include <cstring>
#define LG 1026

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[LG],b[LG],n,m;
int c[LG][LG],v[LG],y=1;
int maxim(int a,int b){
    if(a>b) return a; return b;
}
int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];
    y=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                c[i][j]=maxim(c[i][j-1],c[i-1][j]);
            }
        }
    }
    fout<<c[n][m]<<'\n';
    int i=n,j=m;
    while (i>0 and j>0) {
        while (c[i][j]==c[i-1][j]) i--;
        while (c[i][j]==c[i][j-1]) j--;
        v[c[i][j]] = a[i];
        i--; j--;
    }
    for(int i=1;i<=c[n][m];i++) fout<<v[i]<<' ';
    return 0;
}
