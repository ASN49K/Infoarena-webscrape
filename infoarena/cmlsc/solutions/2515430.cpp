#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int m,n,i,j,k;
int a[1024],b[1024],sir[1024],d[1024][1024];
int main()
{
    fin>>m>>n;
    for (i=1; i<=m; i++)
       fin>>a[i];
    for (i=1; i<=n; i++)
        fin>>b[i];
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
            if (a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    i=m;
    j=n;
    while (i>0)
    {
        if (a[i]==b[j])
        {sir[++k]=a[i];
        i--;
        j--;
        }
        else
            if (d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    fout<<k<<'\n';
    for (i=k; i>0; i--)
        fout<<sir[i]<<' ';
    return 0;
}
