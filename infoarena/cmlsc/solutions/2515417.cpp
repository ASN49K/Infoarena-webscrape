#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int m,n,i,j,k;
int a[1024],b[1024],sir[2048];
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
        {
            sir[++k]=a[i];
            break;
        }
    }
    fout<<k<<'\n';
    for (i=1; i<=k; i++)
        fout<<sir[i]<<' ';
    return 0;
}
