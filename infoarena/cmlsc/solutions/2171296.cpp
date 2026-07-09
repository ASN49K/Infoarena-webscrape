#include <bits/stdc++.h>
#define N 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[N],b[N],d[N][N],sir[N],bst;
int n,m;

void Solve(){
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    for(i=n, j=m; i;)
        if(a[i]==b[j])
            sir[++bst]=a[i], i--,j--;
            else if(d[i-1][j]<d[i][j-1]) j--;
                 else i--;

    fout<<bst<<'\n';
    for(i=bst; i; i--) fout<<sir[i]<<' ';
}

int main()
{
    int i;

    fin>>n>>m;
    for(i=1; i<=n; i++) fin>>a[i];
    for(i=1; i<=m; i++) fin>>b[i];
    fin.close();

    Solve();

    fout.close();
    return 0;
}
