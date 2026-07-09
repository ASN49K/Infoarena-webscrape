#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int i, n, m, mat[1025][1025];
char a[1025], b[1025];

void read(){
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int i=1; i<=m; i++)
        in>>b[i];
}

void con(){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])mat[i][j]=mat[i-1][j-1]+1;
                else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
}

void solve(){
    char c[1025], mx=0;
    for(int i=n, j=m; i; )
        if(a[i]==b[j])c[++mx]=a[i], --i, --j;
            else if(mat[i-1][j]<mat[i][j-1]) --j;
                else --i;

    out<<int(mx)<<'\n';
    for(; mx; --mx)
        out<<c[mx]<<' ';
}

int main(){
    read();
    con();
    solve();
    return 0;
}
