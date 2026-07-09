#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1050],b[1050],i,nr,j,n,m,mat[1050][1050],v[1050];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>a[i];
    for(i=1;i<=m;++i)
        fin>>b[i];
    if(a[1]==b[1])  mat[1][1]=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    fout<<mat[n][m]<<'\n';
    i=n; j=m;
    while(i>0 && j>0)
    {
        if(mat[i][j]==mat[i-1][j-1]+1)
        {
            v[++nr]=a[i];
            i--; j--;
        }
        else if(mat[i][j-1]>=mat[i-1][j])
            j--;
        else i--;
    }
    for(i=nr;i>=1;--i)
        fout<<v[i]<<' ';
    return 0;
}
