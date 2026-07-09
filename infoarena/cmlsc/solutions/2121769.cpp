#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000007
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int L[1025][1025];
int a[1025];
int b[1025];
int c[1025];
int main(){
    int t, n,m,i,j,k=0;
    in>>n>>m;
    for(i=0; i<n; ++i)
        in>>a[i];
    for(i=0; i<m; ++i)
        in>>b[i];
    for(i=1; i<=n; ++i){
        for(j=1; j<=m; ++j){
            if(a[i-1]==b[j-1]){
                L[i][j]=L[i-1][j-1]+1;
            }
            else{
                L[i][j]=max(L[i][j-1], L[i-1][j]);
            }
        }
    }

    i=n, j=m;
    while(j>0 || i>0){
        if(L[i][j-1]!=L[i][j]){
            while(L[i-1][j]==L[i][j])
                --i;
            c[++k]=a[i-1];
            --i;
        }
        --j;
    }
    out<<L[n][m]<<"\n";
    --k;
    for(k; k>=1; --k)
        out<<c[k]<<" ";
    return 0;
}