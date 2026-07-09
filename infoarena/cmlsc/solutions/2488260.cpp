#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1031],b[1031],d[1031][1031],sir[1031],k;

void sv(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i][j-1],d[i-1][j]);
    }
}

bool valid(int x, int y){
    if(d[x-1][y]==d[x][y-1])return 1;
    return 0;
}

int main(){

    f>>n>>m;

    for(int i=1; i<=n; ++i)
        f>>a[i];
    for(int i=1; i<=m; ++i)
        f>>b[i];

    sv();

    for(int i=n, j=m; i;){
        if(a[i]==b[j]){
            sir[++k]=a[i];
            --i;
            --j;
        }
        if(d[i][j-1]<d[i-1][j])--i;
        else --j;
    }

    g<<k<<'\n';
    for(int i=k; i>=1; --i)
        g<<sir[i]<<' ';

    return 0;
}
