#include <bits/stdc++.h>
#define DIM 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,k,a[DIM],b[DIM],sol[DIM],d[DIM][DIM];
int main() {
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    i=n, j=m;
    while (d[i][j]) {
        if (a[i]==b[j]) {
            sol[k++]=a[i];
            i--, j--;
        }
        else if (d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    fout<<d[n][m]<<"\n";
    while (k--)
        fout<<sol[k]<<" ";
    return 0;
}
