#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025];
int c[1025][1025];

void afis_rec(int i,int j)
{
    if(i<1||i>n||j<1||j>m)
        return;
    if(a[i]==b[j])
    {
        afis_rec(i-1,j-1);
        fout<<a[i]<<" ";
    }
    else if(c[i-1][j]>c[i][j-1])
        afis_rec(i-1,j);
    else afis_rec(i,j-1);
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    c[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    fout<<c[n][m]<<'\n';
    afis_rec(n,m);
}
