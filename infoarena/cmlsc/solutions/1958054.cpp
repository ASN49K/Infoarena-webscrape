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
void dn(int n,int a[],int m,int b[]){
    y=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                c[i][j]=c[i-1][j-1]+1;
                v[y]=a[i]; y++;
            }
            else{
                c[i][j]=maxim(c[i][j-1],c[i-1][j]);
            }
        }
    }
    fout<<c[n][m]<<'\n';
    y--;
    for(int i=1;i<=c[n][m];i++) fout<<v[i]<<' ';
}
void solve(){
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];
    dn(n,a,m,b);
}
int main(){
    solve();
    return 0;
}
