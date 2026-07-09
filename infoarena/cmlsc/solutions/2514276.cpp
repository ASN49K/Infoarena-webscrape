#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,a[1030],b[1030],d[1030][1030],i,j,sir[1030];
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    for (i = m, j = n; i; )
    {
        if(a[i]==b[j])
            sir[++sir[0]]=a[i] , i--,j--;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    }
    fout<<sir[0]<<'\n';
    for(i=sir[0];i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
