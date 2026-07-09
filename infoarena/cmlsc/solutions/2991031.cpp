#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short v[1025][1025],a[1025],b[1025];
void afis(int pas,int i,int j)
{
    if(pas==0)return;
    else
    {
        if(a[j]==b[i])
        {
            afis(pas-1,i-1,j-1);
            fout<<b[i]<<' ';
        }
        if(a[j]!=b[i])
        {
            if(v[i-1][j]>=v[i][j-1])
            {
                afis(pas,i-1,j);
            }
            else afis(pas,i,j-1);
        }
    }
}
int main()
{
    int i,n,j,m,s=0;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(b[i]==a[j])v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    fout<<v[m][n]<<'\n';
    afis(v[m][n],m,n);
}

