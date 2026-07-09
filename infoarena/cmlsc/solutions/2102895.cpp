///pt vectorii a si b, gaseste subsirul comun de lungime maxima
/// complexitate O(n*m)
#include <bits/stdc++.h>
#define NMAX 1025
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
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n;
    j=m;
    while(i)
    {
        if(a[i]==b[j])
            sir[++x]=a[i], --i, --j;
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }
    fout<<x<<'\n';
    for(i=x; i>=1; --i)
        fout<<sir[i]<<" ";
    return 0;
}
