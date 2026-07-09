#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX=1025;

int a[NMAX], b[NMAX], l[NMAX][NMAX], n,m,i,j;



int main()
{

   int x=0,y=0;
    f>>n>>m;
    for(i=1; i<=n; ++i)
        f>>a[i];
    for(j=1; j<=m; ++j)
        f>>b[j];
    int k=1;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
    {
        if(a[i] == b[j] && i>x && j>y){ l[i][j]=k; k++; x=i; y=j; }
    }
    g<<k--<<endl;

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
    {
        if(l[i][j]>0) g<<a[i]<<" ";
    }


    return 0;
}
