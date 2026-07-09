///pt vectorii a si b, gaseste subsirul comun de lungime maxima
/// complexitate O(n*m)
#include <bits/stdc++.h>
#define NMAX 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NMAX], b[NMAX], d[NMAX][NMAX], sir[NMAX], n, m, x;

int main()
{
    int i, j;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>a[i];
    for(i=1; i<=m; ++i)
        fin>>b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[i])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    for(i=n, j=m; i>0,j>0;)
        if(a[i]==b[j])
            sir[++x]=a[i], i--, j--;
        else
        {
            if(d[i][j-1]>d[i-1][j])
                j--;
            else
                i--;
        }
    fout<<x<<'\n';
    for(i=x; i; i--)
        fout<<sir[i]<<" ";
    return 0;
}
