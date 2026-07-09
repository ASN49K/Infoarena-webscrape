#include <bits/stdc++.h>

using namespace std;
ifstream in  ("cmscl.in");
ofstream out("cmscl.out");

#define maxN 1024

int a[maxN+1];
int b[maxN+1];
int d[maxN+1][maxN+1];
int v[maxN*maxN+1];

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
    int i=n,j=m;

    while(maxi>0){
        if(d[i-1][j]==maxi){
            i--;
        }
        else if(d[i][j-1]==maxi){
            j--;
        }
        else{
            i--;
            j--;
            maxi--;
            v[maxi]=a[i+1];
        }
    }

    out<<d[n][m]<<'\n';
    for(i=0;i<d[n][m];i++){
        out<<v[i]<<" ";
    }
}
