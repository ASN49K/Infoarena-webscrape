#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,d[1030][1030],a[1030],b[1030];
void drum(int x,int y,int k){
 if(k){
    if(a[x]==b[y]){
        drum(x-1,y-1,k-1);
        fout<<a[x]<<' ';
    }
    else{
        if(d[x-1][y]>d[x][y-1])drum(x-1,y,k);
        else drum(x,y-1,k);
    }
 }
}
int main(){
 fin>>n>>m;
 for(int i=1;i<=n;i++)fin>>a[i];
 for(int i=1;i<=m;i++)fin>>b[i];
 for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(a[i]==b[j]){
            d[i][j]=d[i-1][j-1]+1;
        }
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
 }
 fout<<d[n][m]<<'\n';
 drum(n,m,d[n][m]);
}
