#include <bits/stdc++.h>

using namespace std;
ifstream in  ("cmscl.in");
ofstream out("cmscl.out");

#define maxN 1024

int a[maxN+1];
int b[maxN+1];
int d[maxN+1][maxN+1];
int v[maxN+1];

int main(){
    int n,m;
    in>>n>>m;
    for(int i=1;i<=n;i++){
        in>>a[i];
    }
    for(int i=1;i<=m;i++){
        in>>b[i];
    }
    d[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                d[i][j]=d[i-1][j-1]+1;
            }
            else{
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    int maxi=d[n][m];
    int nr=0;
    int i=n,j=m;

    while(i){
        if(a[i]==b[j]){
            nr++;
            v[nr]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1]){
            j--;
        }
        else{
            i--;
        }
    }

    out<<d[n][m]<<'\n';
    for(i=nr;i>=1;i--){
        out<<v[i]<<" ";
    }
}
