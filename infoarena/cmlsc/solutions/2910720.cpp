#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int const N=1025;
int n,m,bst;
int a[N],b[N],sir[N];
int d[N][N];


int main()

{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int j=1; j<=m; j++)
    {
        fin>>b[j];
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]== b[j])
                d[i][j] = 1+ d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);

    for(int i=n,j=m; i;)
        if(a[i]==b[j])
            sir[++bst]=a[i],--i,--j;
        else if (d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;

    fout<<bst<<'\n';
    for(int i = bst; i; i--)
        fout<<sir[i]<<' ';


    return 0;
}
